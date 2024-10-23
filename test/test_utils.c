#include "../src/utils.h"
#include <assert.h>
#include <stdio.h>

void test_load_config() {
    Config config;
    int result = load_config("../src/config.json", &config);
    assert(result == 0);
    assert(config.num_pages == 256);
    assert(config.num_frames == 64);
}

void run_tests() {
    test_load_config();
    printf("All tests passed.\n");
}

int main() {
    run_tests();
    return 0;
}
