#!/bin/bash

echo "Running tests..."

gcc -o test_vmm test/test_vmm.c src/vmm.c src/utils.c
./test_vmm

gcc -o test_utils test/test_utils.c src/utils.c
./test_utils

echo "All tests completed."
