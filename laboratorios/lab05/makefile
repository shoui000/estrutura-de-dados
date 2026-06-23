CC := gcc
CFLAGS := -Wall -Wextra
VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --track-origins=yes

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TEST_DIR := tests

SRC := $(shell find $(SRC_DIR) -name "*.c" | tr '\n' ' ')
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

TEST_INPUT := $(TEST_DIR)/entrada.txt
TEST_OUTPUT := $(TEST_DIR)/gabarito.txt

TARGET := $(BIN_DIR)/programa
OUTPUT := $(BIN_DIR)/output.out

.PHONY: all clean test

all: $(TARGET) 

$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(TARGET) 
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

test: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) $(TARGET) $(TEST_INPUT) $(OUTPUT)
	diff $(OUTPUT) $(TEST_OUTPUT)
