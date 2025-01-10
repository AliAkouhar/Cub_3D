#!/bin/bash

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Check if Makefile exists in the current directory
if [ ! -f Makefile ]; then
    echo -e "${RED}Error: No Makefile found in the current directory.${NC}"
    exit 1
fi

# Run make
echo "Running make..."
make
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Build successful.${NC}"
else
    echo -e "${RED}Build failed.${NC}"
    exit 1
fi

# Run make clean
echo "Cleaning build files..."
make clean
if [ $? -eq 0 ]; then
    echo -e "${GREEN}Clean successful.${NC}"
else
    echo -e "${RED}Clean failed.${NC}"
    exit 1
fi
