#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

void init_semaphore(int semid) {
    // Initialize semaphore to 1 (binary semaphore)
    semctl(semid, 0, SETVAL, 1);
}

void send_message_to_oss(int process_id, int address, int write) {
    // Send a message from the user process to the master (oss)
    printf("User process %d requesting address %d for %s\n", process_id, address, write ? "write" : "read");
}

void wait_for_semaphore(int semid) {
    struct sembuf sop = { 0, -1, 0 };
    semop(semid, &sop, 1);
}

void signal_semaphore(int semid) {
    struct sembuf sop = { 0, 1, 0 };
    semop(semid, &sop, 1);
}
