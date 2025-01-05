#!/bin/bash

set -e # Exit early if any commands fail

cd "$(dirname "$0")" # Ensure compile steps are run within the repository directory
cmake -B build -S . -D CMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
cmake --build ./build

# Copied from .codecrafters/run.sh
#
# - Edit this to change how your program runs locally
# - Edit .codecrafters/run.sh to change how your program runs remotely
# exec ./build/Debug/regex-engine-cpp.exe "$@"