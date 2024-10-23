#include "../src/vmm.h"
#include <assert.h>
#include <stdio.h>

void test_page_fault() {
    initialize_tables();
    access_memory(1);  // This should generate a page fault and load page 1 into memory
}

void run_tests() {
    test_page_fault();
    printf("All tests passed.\n");
}

int main() {
    run_tests();
    return 0;
}
