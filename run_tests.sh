#!/bin/bash

# Simple script to test the push_swap project

# --- Colors for pretty printing ---
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# --- Test Runner Function ---
# Arguments:
# $1: Test name (e.g., "5 numbers")
# $2: Maximum allowed operations (use 0 for no limit)
# $3: The list of numbers to test, as a string (e.g., "3 1 2")
run_test() {
    local test_name="$1"
    local max_ops="$2"
    local numbers="$3"

    echo -e "${BLUE}--- Running Test: $test_name ---${NC}"
    echo "Input: $numbers"

    # Execute push_swap and capture its output (the operations)
    # Use a timeout to prevent infinite loops
    ops=$(timeout 5s ./push_swap $numbers)

    # Check if push_swap produced any output
    if [ -z "$ops" ]; then
        # This is expected for an already sorted list
        op_count=0
        checker_output="OK"
    else
        # Count the number of operations
        op_count=$(echo "$ops" | wc -l | tr -d ' ')
        # Verify the output with the checker
        checker_output=$(echo "$ops" | ./checker $numbers)
    fi

    # Determine the test status
    local status="${RED}FAIL${NC}"
    local reason=""

    if [ "$checker_output" != "OK" ]; then
        reason="Checker returned KO"
    elif [ "$max_ops" -ne 0 ] && [ "$op_count" -gt "$max_ops" ]; then
        reason="Exceeded max operations"
    else
        status="${GREEN}PASS${NC}"
    fi

    echo "Operations: $op_count"
    if [ "$max_ops" -ne 0 ]; then
        echo "Target: <= $max_ops operations"
    fi
    echo "Checker: $checker_output"
    echo -e "Status: $status ${reason:+$RED($reason)$NC}"
    echo "-----------------------------------"
    echo
}

# --- Error Case Test Runner ---
# Verifies that push_swap prints "Error" for invalid input
run_error_test() {
    local test_name="$1"
    local numbers="$2"

    echo -e "${BLUE}--- Running Test: $test_name ---${NC}"
    echo "Input: $numbers"

    # Execute push_swap and capture stderr, which is where the program writes "Error"
    error_output=$(./push_swap $numbers 2>&1)

    # Determine status
    local status="${RED}FAIL${NC}"
    # The program should just output "Error" and nothing else
    if [[ "$error_output" == "Error" ]]; then
        status="${GREEN}PASS${NC}"
    fi

    echo "Output: $error_output"
    echo -e "Status: $status"
    echo "-----------------------------------"
    echo
}


# --- Generate Random Numbers ---
# Uses `shuf` to generate a space-separated list of unique random numbers
# $1: Count of numbers
# $2: Max value
generate_numbers() {
    shuf -i 1-$2 -n $1 | tr '\n' ' '
}


# ==============================================================================
# --- EXECUTE TESTS ---
# ==============================================================================

echo "Starting push_swap test suite..."
echo

# --- Simple Tests ---
run_test "3 Numbers" 3 "2 1 0"
run_test "5 Numbers" 12 "4 5 1 3 2"

# --- Edge Case Tests ---
run_error_test "Duplicates" "1 2 3 2"
run_error_test "Non-numeric" "1 2 three 4"
run_test "Already Sorted" 0 "0 1 2 3 4 5"
run_test "Negative Numbers" 0 "-5 2 -10 0 8"
run_test "Single Number" 0 "42"

# --- Efficiency Tests ---
echo -e "${BLUE}--- Generating 100 random numbers... ---${NC}"
NUMS_100=$(generate_numbers 100 1000)
run_test "100 Random Numbers" 699 "$NUMS_100" # Max is *fewer than* 700

echo -e "${BLUE}--- Generating 500 random numbers... ---${NC}"
NUMS_500=$(generate_numbers 500 5000)
run_test "500 Random Numbers" 5500 "$NUMS_500"
