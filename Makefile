CC = gcc
CFLAGS = -Wall -g

# List of source files
SRC = main.c user_process.c memory_management.c communication.c frame_table.c utils.c
OBJ = $(SRC:.c=.o)
EXEC = oss

# Default target to build the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)
