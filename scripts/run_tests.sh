#!/bin/bash
set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

if [ $# -eq 1 ]; then
    TARGET_PROBLEM="$1"
    echo -e "${BLUE}Testing only problem: $TARGET_PROBLEM${NC}"
    PROBLEM_DIRS=("src/$TARGET_PROBLEM")
else
    echo -e "${BLUE}Testing all problems...${NC}"
    PROBLEM_DIRS=(src/*/*)
fi

if [ ! -d "build" ]; then
    echo -e "${YELLOW}Build directory not found. Building projects...${NC}"
    ./scripts/build_all.sh
fi

TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

normalize_output() {
    echo "$1" | sed 's/[[:space:]]\+/ /g' | sed 's/^ //' | sed 's/ $//' | tr -d '\r'
}

compare_output() {
    local actual="$1"
    local expected="$2"

    actual_norm=$(normalize_output "$actual")
    expected_norm=$(normalize_output "$expected")

    if [ "$actual_norm" = "$expected_norm" ]; then
        return 0
    else
        return 1
    fi
}

for PROBLEM_DIR in "${PROBLEM_DIRS[@]}"; do
    SECTION_NAME=$(basename "$(dirname "$PROBLEM_DIR")")
    PROBLEM_NAME=$(basename "$PROBLEM_DIR")
    EXEC_NAME="${SECTION_NAME}-${PROBLEM_NAME}"

    EXEC_PATH="build/${EXEC_NAME}"

    if [ ! -f "$EXEC_PATH" ]; then
        echo -e "${YELLOW}Executable $EXEC_PATH not found. Skipping...${NC}"
        continue
    fi

    TESTS_DIR="${PROBLEM_DIR}/tests"
    if [ ! -d "$TESTS_DIR" ]; then
        echo -e "${YELLOW}Tests directory not found for $EXEC_NAME. Skipping...${NC}"
        continue
    fi

    echo -e "\n${BLUE}=== Testing $EXEC_NAME ===${NC}"

    TEST_FILES=("$TESTS_DIR"/*.in)

    if [ ${#TEST_FILES[@]} -eq 0 ]; then
        echo -e "${YELLOW}No test files (.in) found for $EXEC_NAME${NC}"
        continue
    fi

    for TEST_IN in "${TEST_FILES[@]}"; do
        TEST_BASE=$(basename "$TEST_IN" .in)
        TEST_OUT="${TESTS_DIR}/${TEST_BASE}.out"

        if [ ! -f "$TEST_OUT" ]; then
            echo -e "${YELLOW}  Skipping $TEST_BASE: no .out file${NC}"
            continue
        fi

        TOTAL_TESTS=$((TOTAL_TESTS + 1))

        echo -n "  Test $TEST_BASE: "

        START_TIME=$(date +%s%N)
        ACTUAL_OUTPUT=$("$EXEC_PATH" < "$TEST_IN")
        EXIT_CODE=$?
        END_TIME=$(date +%s%N)
        ELAPSED_TIME=$(( (END_TIME - START_TIME) / 1000000 ))

        if [ $EXIT_CODE -ne 0 ]; then
            echo -e "${RED}ERROR (code: $EXIT_CODE)${NC}"
            FAILED_TESTS=$((FAILED_TESTS + 1))
            continue
        fi

        EXPECTED_OUTPUT=$(cat "$TEST_OUT")

        if compare_output "$ACTUAL_OUTPUT" "$EXPECTED_OUTPUT"; then
            echo -e "${GREEN}PASSED${NC} (${ELAPSED_TIME}ms)"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}FAILED${NC} (${ELAPSED_TIME}ms)"
            echo -e "    Expected: '$EXPECTED_OUTPUT'"
            echo -e "    Got:      '$ACTUAL_OUTPUT'"
            FAILED_TESTS=$((FAILED_TESTS + 1))
        fi
    done
done

echo -e "\n${BLUE}=== SUMMARY ===${NC}"
echo -e "Total tests: $TOTAL_TESTS"
echo -e "${GREEN}Passed: $PASSED_TESTS${NC}"
if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}Failed: $FAILED_TESTS${NC}"
    exit 0
else
    echo -e "${RED}Failed: $FAILED_TESTS${NC}"
    exit 1
fi
