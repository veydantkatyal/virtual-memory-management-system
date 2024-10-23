#include "vmm.h"
#include <stdio.h>
#include <stdlib.h>

PageTableEntry page_table[NUM_PAGES];
FrameTableEntry frame_table[NUM_FRAMES];
int fifo_queue[NUM_FRAMES];
int queue_index = 0;

void initialize_tables() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i].page_number = i;
        page_table[i].frame_number = -1;
        page_table[i].valid = 0;
    }
    for (int i = 0; i < NUM_FRAMES; i++) {
        frame_table[i].frame_number = i;
        frame_table[i].is_free = 1;
        fifo_queue[i] = -1;
    }
}

int find_free_frame() {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frame_table[i].is_free) {
            return i;
        }
    }
    return -1;
}

int fifo_replacement() {
    int frame_to_replace = fifo_queue[queue_index];
    queue_index = (queue_index + 1) % NUM_FRAMES;
    return frame_to_replace;
}

void handle_page_fault(int page_number) {
    int frame_number = find_free_frame();

    if (frame_number == -1) {
        frame_number = fifo_replacement();
        printf("Page replacement occurred! Replaced frame %d\n", frame_number);
    } else {
        printf("Page %d loaded into frame %d\n", page_number, frame_number);
    }

    page_table[page_number].frame_number = frame_number;
    page_table[page_number].valid = 1;
    frame_table[frame_number].is_free = 0;

    fifo_queue[frame_number] = page_number;
}

void access_memory(int page_number) {
    if (page_table[page_number].valid) {
        printf("Page %d is already in memory at frame %d\n", page_number, page_table[page_number].frame_number);
    } else {
        printf("Page fault! Page %d not in memory.\n", page_number);
        handle_page_fault(page_number);
    }
}

void simulate_process(int page_accesses[], int num_accesses) {
    for (int i = 0; i < num_accesses; i++) {
        access_memory(page_accesses[i]);
    }
}
