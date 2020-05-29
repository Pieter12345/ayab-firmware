#!/bin/bash
set -e
OPTIND=1
verbose=0
# parse arguments
while getopts "v" opt; do
    case $opt in
        v)   verbose=1
             ;;
    esac
done
shift $((OPTIND-1))
[ "${1:-}" = "--" ] && shift

# change to script directory
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$parent_path"

mkdir -p build
cd build
cmake ..
if [[ $verbose -eq 1 ]]; then
make VERBOSE=1
GTEST_COLOR=1 ctest -V --output-on-failure .
else
make
GTEST_COLOR=1 ctest --output-on-failure .
fi
cd ../..
gcovr -r . -e test_* -e arduino_mock* -e libraries* --html-details -o ./test/build/coverage.html
gcovr -r . -e test_* -e arduino_mock* -e libraries*
gcovr -r . --branches -e test_* -e arduino_mock* -e libraries*