#!/bin/bash

set -e # Exit early if any commands fail

exec ./build/Debug/regex-engine-cpp.exe "$@"