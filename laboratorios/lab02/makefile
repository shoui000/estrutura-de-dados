CC = gcc
CFLAGS = -Wall

BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
TEST_DIR = $(BIN_DIR)/test

TARGET = $(BIN_DIR)/pograma
INPUT_FILE = input.txt
OUTPUT_FILE = output.txt
GABARITO_FILE = gabarito.txt

.PHONY: all build test clean

all: clean build test

build:
	mkdir -p $(BIN_DIR)
	cp *.c $(BUILD_DIR)
	cp *.h $(BUILD_DIR)
	${CC} ${CFLAGS} -o $(TARGET) $(BUILD_DIR)/*.c

test: build
	mkdir -p $(TEST_DIR)
	cp $(INPUT_FILE) $(TEST_DIR)
	cp $(GABARITO_FILE) $(TEST_DIR)
	$(TARGET) $(TEST_DIR)/$(INPUT_FILE) $(TEST_DIR)/$(OUTPUT_FILE)
	diff $(TEST_DIR)/$(OUTPUT_FILE) $(TEST_DIR)/$(GABARITO_FILE)

clean:
	rm -rf $(BUILD_DIR)
