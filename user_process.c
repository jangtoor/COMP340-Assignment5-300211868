#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "communication.h"

void user_process(int process_id, Time *logical_clock) {
    while (1) {
        // Generate a random memory access
        unsigned int address = rand() % 32768; // Process memory limit
        unsigned int read_write = rand() % 2; // 0 = read, 1 = write

        // Send memory access request to master (oss)
        send_memory_request(process_id, address, read_write);

        // Wait for response (synchronize with master process)
        wait_for_response();

        // Randomly check if this process should terminate
        if (rand() % 1000 < 10) {  // ~1% chance of termination
            printf("Process %d terminating\n", process_id);
            terminate_process(process_id);
            break;
        }
    }
}
