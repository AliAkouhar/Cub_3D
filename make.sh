#!/bin/bash

# Check if Makefile exists in the current directory
if [ ! -f Makefile ]; then
    echo "Error: No Makefile found in the current directory."
    exit 1
fi

# Run make
echo "Running make..."
make
if [ $? -eq 0 ]; then
    echo "Build successful."
else
    echo "Build failed."
    exit 1
fi

# Run make clean
echo "Cleaning build files..."
make clean
if [ $? -eq 0 ]; then
    echo "Clean successful."
else
    echo "Clean failed."
    exit 1
fi
