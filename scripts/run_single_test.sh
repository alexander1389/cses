#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <section> <problem> <test_number>"
    echo "Example: $0 01-introductory-problems 01-weird-algorithm 1"
    exit 1
fi

SECTION="$1"
PROBLEM="$2"
TEST_NUM="$3"

EXEC_NAME="${SECTION}-${PROBLEM}"
EXEC_PATH="build/${EXEC_NAME}"
TESTS_DIR="src/${SECTION}/${PROBLEM}/tests"

if [ ! -f "$EXEC_PATH" ]; then
    echo "Error: executable $EXEC_PATH not found"
    exit 1
fi

TEST_IN="${TESTS_DIR}/${TEST_NUM}.in"
TEST_OUT="${TESTS_DIR}/${TEST_NUM}.out"

if [ ! -f "$TEST_IN" ]; then
    echo "Error: input file $TEST_IN not found"
    exit 1
fi

if [ ! -f "$TEST_OUT" ]; then
    echo "Error: output file $TEST_OUT not found"
    exit 1
fi

echo "Running test $TEST_NUM for $EXEC_NAME"
echo "Input:"
cat "$TEST_IN"
echo -e "\nExpected output:"
cat "$TEST_OUT"

echo -e "\nActual output:"
"$EXEC_PATH" < "$TEST_IN"
