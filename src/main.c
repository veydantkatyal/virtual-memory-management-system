#include "vmm.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("Starting Virtual Memory Management System...\n");

    // Load configuration
    Config config;
    if (load_config("config.json", &config) == -1) {
        printf("Error loading config. Using default settings.\n");
        config.num_pages = NUM_PAGES;
        config.num_frames = NUM_FRAMES;
    }

    printf("Configuration: %d pages, %d frames\n", config.num_pages, config.num_frames);

    // Initialize tables
    initialize_tables();

    // Simulate process memory accesses
    int page_accesses[] = {1, 2, 3, 4, 5, 6, 1, 7, 8, 9, 3, 4, 5};
    simulate_process(page_accesses, sizeof(page_accesses) / sizeof(int));

    return 0;
}
