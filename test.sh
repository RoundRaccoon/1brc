#!/bin/bash

# Check if exactly two arguments are passed
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <binary_name> <input_file>"
    exit 1
fi

# Arguments
BINARY_NAME=$1
INPUT_FILE=$2

# Paths
BINARY_PATH="bin/$BINARY_NAME"
INPUT_PATH="in/$INPUT_FILE"
REFERENCE_PATH="ref/$INPUT_FILE"
OUTPUT_PATH="out/$INPUT_FILE"

# Check if binary exists
if [ ! -x "$BINARY_PATH" ]; then
    echo "Error: Binary '$BINARY_PATH' not found or is not executable."
    exit 1
fi

# Check if input file exists
if [ ! -f "$INPUT_PATH" ]; then
    echo "Error: Input file '$INPUT_PATH' not found."
    exit 1
fi

# Check if reference file exists
if [ ! -f "$REFERENCE_PATH" ]; then
    echo "Error: Reference file '$REFERENCE_PATH' not found."
    exit 1
fi

# Ensure the output directory exists
mkdir -p "$(dirname "$OUTPUT_PATH")"

# Run the binary with input and measure execution time
echo "Running the binary..."
{ time "$BINARY_PATH" "$INPUT_PATH" > "$OUTPUT_PATH"; } 2> time.log

# Extract timing information
EXECUTION_TIME=$(grep real time.log | awk '{print $2}')

# Compare the output with the reference file
if diff -q "$OUTPUT_PATH" "$REFERENCE_PATH" > /dev/null; then
    echo "Correct: The outputs match."
else
    echo "Incorrect: The outputs do not match."
fi

# Print execution time
echo "Execution time: $EXECUTION_TIME"

# Clean up time log
rm -f time.log
