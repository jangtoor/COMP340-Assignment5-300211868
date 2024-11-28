# COMP340-Assignment5-300211868

# Simulator for Operating Systems: Memory Management

## Summary
This project uses a unique page replacement technique with memory access logging to mimic operating system memory management. In addition, the system manages I/O delays, dirty bits, and page faults.

## Documents
Child processes are coordinated by the master process (oss), which is implemented by `main.c`.
The child processes that mimic user programs are implemented by `user_process.c`.
- `memory_management.c`: Manages memory, including dirty bits, reference bits, and frame allocation.
- `communication.c`: Uses semaphores or message queues to manage inter-process communication.
- `frame_table.c`: Oversees the page replacement algorithm and frame table.
- `utils.c`: Provides time management and logging utility routines.

## Gathering
To complete the project compilation, execute: ```bash make
