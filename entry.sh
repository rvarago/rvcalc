#!/bin/bash

set -euo pipefail

function buildProject {
    mkdir -p build
    cd build

    cmake ..
    cmake --build .
}

function showUsage {
    echo "usage: entry.sh <what>"
    echo "<what>: app or test"
}

if [[ $# -ne 1 ]]; then
    showUsage "$@"
    exit 1
fi

buildProject

case "$1" in
    app)
        ./app/rvcalc
    ;;
    test)
        ./test/rvcalc_tests
    ;;
    *)
        showUsage
        exit 1
esac

exit 0