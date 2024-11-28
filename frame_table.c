#include <stdio.h>

#define MAX_FRAMES 256

typedef struct {
    unsigned char reference_byte;
    unsigned char dirty_bit;
    unsigned char occupied;
} Frame;

Frame frame_table[MAX_FRAMES];

// Find an empty frame
int find_empty_frame() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frame_table[i].occupied == 0) {
            return i;
        }
    }
    return -1;  // No empty frame found
}

// Find a victim frame for replacement based on reference bits
int find_victim_frame() {
    int min_ref_byte = 256;
    int victim_frame = -1;
    
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frame_table[i].occupied && frame_table[i].reference_byte < min_ref_byte) {
            min_ref_byte = frame_table[i].reference_byte;
            victim_frame = i;
        }
    }
    
    return victim_frame;
}
