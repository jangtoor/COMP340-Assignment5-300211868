
### 4. **Main Program (`main.c`)**

This file will contain the master process (`oss`), which handles memory management, process creation, and inter-process communication.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include "memory_management.h"
#include "frame_table.h"
#include "communication.h"

#define MAX_PROCESSES 18
#define SHM_SIZE 1024

// Structure for logical time
typedef struct {
    unsigned int sec;
    unsigned int nsec;
} Time;

int main(int argc, char *argv[]) {
    int max_children = MAX_PROCESSES;

    // Parse arguments
    if (argc > 1) {
        max_children = atoi(argv[1]);
        if (max_children > MAX_PROCESSES) max_children = MAX_PROCESSES;
    }

    // Setup shared memory for system resources (e.g., page table, frame table)
    int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("Shared memory allocation failed");
        exit(1);
    }

    // Attach to shared memory
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("Shmat failed");
        exit(1);
    }

    // Initialize system resources (e.g., frame table, page table, etc.)
    init_frame_table();
    init_page_table();

    // Main clock
    Time logical_clock = {0, 0};

    // Fork processes
    for (int i = 0; i < max_children; i++) {
        if (fork() == 0) {
            // Child process (user process)
            user_process(i, &logical_clock);
            exit(0);
        }
    }

    // Monitor memory accesses, page faults, and log events
    while (1) {
        check_page_faults();
        usleep(10000); // Simulate small time advances (10 ms)
    }

    // Cleanup shared memory before exit
    shmdt(shm_ptr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
