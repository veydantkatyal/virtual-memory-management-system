#ifndef VMM_H
#define VMM_H

#define NUM_PAGES 256
#define NUM_FRAMES 64

typedef struct {
    int page_number;
    int frame_number;
    int valid;
} PageTableEntry;

typedef struct {
    int frame_number;
    int is_free;
} FrameTableEntry;

void initialize_tables();
void access_memory(int page_number);
void handle_page_fault(int page_number);
int find_free_frame();
int fifo_replacement();
void simulate_process(int page_accesses[], int num_accesses);

#endif
