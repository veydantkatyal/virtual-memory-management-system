#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_config(const char *filename, Config *config) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open config file.\n");
        return -1;
    }

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        // Parse the number of pages
        if (strncmp(line, "num_pages=", 10) == 0) {
            sscanf(line + 10, "%d", &config->num_pages);
        }
        // Parse the number of frames
        else if (strncmp(line, "num_frames=", 11) == 0) {
            sscanf(line + 11, "%d", &config->num_frames);
        }
    }

    fclose(file);
    return 0;
}
