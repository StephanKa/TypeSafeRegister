# syntax=docker/dockerfile:1.7

# =================================
# Build and test environment for CI
# =================================

FROM ubuntu:24.04 as cpp-docker-common

ARG DEBIAN_FRONTEND=noninteractive
ARG CLANG_COMPILER_VERSION=22
ARG CMAKE_VERSION=3.30.5
ARG IWYU_REF=clang_22
ENV PATH="${PATH}:/cmake-${CMAKE_VERSION}-linux-x86_64/bin/:"

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
  apt-get update && apt-get -y install --no-install-recommends \
  binutils \
  build-essential \
  bzip2 \
  cppcheck \
  ccache \
  doxygen \
  graphviz \
  git \
  lsb-release \
  ninja-build \
  pipx \
  python3 \
  python3-pip \
  python3-setuptools \
  python3-venv \
  shellcheck \
  ssh \
  software-properties-common \
  sudo \
  tar \
  valgrind \
  wget \
  && rm -rf /var/lib/apt/lists/*

RUN set -eux; \
    cmake_installer="cmake-${CMAKE_VERSION}-linux-x86_64.sh"; \
    cmake_release="https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}"; \
    wget "${cmake_release}/${cmake_installer}"; \
    wget -O cmake-SHA-256.txt "${cmake_release}/cmake-${CMAKE_VERSION}-SHA-256.txt"; \
    grep " ${cmake_installer}$" cmake-SHA-256.txt | sha256sum --check; \
    chmod +x cmake-${CMAKE_VERSION}-linux-x86_64.sh  \
    && ./cmake-${CMAKE_VERSION}-linux-x86_64.sh --include-subdir --skip-license \
    && rm cmake-${CMAKE_VERSION}-linux-x86_64.sh cmake-SHA-256.txt
RUN wget -O /tmp/llvm.sh https://apt.llvm.org/llvm.sh \
    && bash /tmp/llvm.sh ${CLANG_COMPILER_VERSION} \
    && rm /tmp/llvm.sh

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
  apt-get update && apt-get -y install --no-install-recommends \
    clang-format-${CLANG_COMPILER_VERSION} \
    clang-tidy-${CLANG_COMPILER_VERSION} \
    llvm-${CLANG_COMPILER_VERSION}-dev \
    libclang-${CLANG_COMPILER_VERSION}-dev \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir iwyu && cd iwyu \
    && git clone --depth 1 --branch ${IWYU_REF} https://github.com/include-what-you-use/include-what-you-use.git \
    && mkdir build && cd build \
    && cmake -G "Ninja" -DCMAKE_PREFIX_PATH=/usr/lib/llvm-${CLANG_COMPILER_VERSION} ../include-what-you-use \
    && ninja install \
    && cd ../.. \
    && rm -rf iwyu


# =================================
# DEV environment for local machine
# =================================

FROM cpp-docker-common as cpp-docker-dev

ARG DEV_USER=dev
ARG DEV_UID=1000
ARG DEV_GID=1000
ENV PATH="${PATH}:/home/${DEV_USER}/.local/bin/"

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
  apt-get update && apt-get -y install --no-install-recommends vim \
  && rm -rf /var/lib/apt/lists/*

# Dev user for inside the container
RUN groupadd -f -g ${DEV_GID} ${DEV_USER} && \
  useradd --non-unique -m -u ${DEV_UID} -g ${DEV_GID} -d /home/${DEV_USER} -s /bin/bash ${DEV_USER} && \
  echo "${DEV_USER} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/${DEV_USER} && \
  chmod 0440 /etc/sudoers.d/${DEV_USER}

# fix "Missing privilege separation directory" error in SSHD
# see: https://bugs.launchpad.net/ubuntu/+source/openssh/+bug/45234
RUN chmod 0755 /var/run/sshd

COPY ccache.conf /etc/.

USER ${DEV_USER}
WORKDIR /home/${DEV_USER}

RUN sed -i 's/\\h/docker/;s/01;32m/01;33m/' /home/${DEV_USER}/.bashrc \
  && mkdir -p /home/${DEV_USER}/git /home/${DEV_USER}/.cache/ccache

RUN pipx install conan==2.7.1


FROM cpp-docker-common as cpp-docker-ci

ARG CI_USER=ci
ENV PATH="${PATH}:/home/${CI_USER}/.local/bin/"

# CI user inside the container
RUN groupadd -f -g 1000 ${CI_USER} && \
  useradd --non-unique -m -u 1000 -g 1000 -d /home/${CI_USER} -s /bin/bash ${CI_USER}

COPY ccache.conf /etc/.
USER ${CI_USER}
RUN pipx install conan==2.7.1
WORKDIR /home/${CI_USER}
