# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Iincludes -g

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN := $(OBJ_DIR)/feige_fiat_shamir_id_scheme

# Sources and objects
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link object files into binary
$(BIN): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Linked -> $@"

# Compile each .c file into .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled -> $<"

# Clean build files
clean:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned."

# Optional: run
run: all
	$(BIN)

.PHONY: all clean run
