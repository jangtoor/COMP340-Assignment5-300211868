#include <stdio.h>
#include <sys/msg.h>

void send_memory_request(int process_id, unsigned int address, unsigned int read_write) {
    // Placeholder: Send a memory request message to the master
    printf("Process %d requesting memory access at address %u (Read/Write: %u)\n", process_id, address, read_write);
}

void wait_for_response() {
    // Placeholder: Simulate waiting for a response
    usleep(100);  // Sleep for 100 ms to simulate waiting
