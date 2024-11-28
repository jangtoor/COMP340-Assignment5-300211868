#include <stdio.h>
#include <stdlib.h>
#include "frame_table.h"
#include "memory_management.h"

#define MAX_FRAMES 256
#define PAGE_SIZE 1024

// Initialize frame table
void init_frame_table() {
    // Initialize frame table with zeroed reference bits and dirty bits
    for (int i = 0; i < MAX_FRAMES; i++) {
        frame_table[i].reference_byte = 0;
        frame_table[i].dirty_bit = 0;
        frame_table[i].occupied = 0;
    }
}

// Handle page faults
void handle_page_fault(int process_id, unsigned int address) {
    // Find an available frame or one with the least recent reference
    int frame_id = find_empty_frame();
    if (frame_id == -1) {
        frame_id = find_victim_frame();
    }

    // Swap in page to frame and reset reference byte
    swap_page_in(process_id, address, frame_id);
}

// Swap a page into a frame
void swap_page_in(int process_id, unsigned int address, int frame_id) {
    // For now, we simulate swapping the page in and reset reference byte
    frame_table[frame_id].reference_byte = 0;
    frame_table[frame_id].dirty_bit = 0;
    frame_table[frame_id].occupied = 1;

    printf("Page fault: Swapping page for process %d at address %u into frame %d\n", process_id, address, frame_id);
}
