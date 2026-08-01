#!/bin/bash -e

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

DOCKER_BUILDKIT=1 docker -l debug build \
    -f "${SCRIPT_DIR}/Dockerfile" \
    --target cpp-docker-ci \
    --build-arg CI_USER=ci \
    -t cpp_ci_env:latest "${SCRIPT_DIR}"
