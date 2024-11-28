#include <stdio.h>

void log_memory_access(int process_id, int address, int frame_num, int write) {
    printf("Master: P%d requesting %s of address %d at time %d:%d\n",
           process_id, write ? "write" : "read", address, 0, 0);  // Example: use real time here
}
