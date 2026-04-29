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

TEST_INPUT_1 := $(TEST_DIR)/entrada1.txt
TEST_INPUT_2 := $(TEST_DIR)/entrada2.txt
TEST_OUTPUT_1 := $(TEST_DIR)/gabarito1.txt
TEST_OUTPUT_2 := $(TEST_DIR)/gabarito2.txt

TARGET := $(BIN_DIR)/programa
OUTPUT_1 := $(BIN_DIR)/output_1.out
OUTPUT_2 := $(BIN_DIR)/output_2.out

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
	$(VALGRIND) $(VALGRIND_FLAGS) $(TARGET) $(TEST_INPUT_1) $(TEST_INPUT_2) $(OUTPUT_1) $(OUTPUT_2)
	diff $(OUTPUT_1) $(TEST_OUTPUT_1)
	diff $(OUTPUT_2) $(TEST_OUTPUT_2)
