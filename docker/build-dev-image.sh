#!/bin/bash -e

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

DOCKER_BUILDKIT=1 docker -l debug build \
    -f "${SCRIPT_DIR}/Dockerfile" \
    --target cpp-docker-dev \
    --build-arg DEV_USER=dev \
    -t cpp_dev_env:latest "${SCRIPT_DIR}"
