#ifndef UTILS_H
#define UTILS_H

typedef struct {
    int num_pages;
    int num_frames;
} Config;

int load_config(const char *filename, Config *config);

#endif
