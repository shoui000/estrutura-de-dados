TARGET = programa

CC = gcc
CFLAGS = -Wall -Iinclude -Isrc/lib

SRC_DIR = src
OBJ_DIR = obj
IN_DIR = inputs
OUT_DIR = outputs
TEST_OUT = out_test

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1

SRCS = $(wildcard $(SRC_DIR)/lib/*.c) $(wildcard $(SRC_DIR)/*.c) 
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TESTS = $(patsubst $(IN_DIR)/%.txt, %, $(wildcard $(IN_DIR)/*.txt))

.PHONY: all clean test $(TESTS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	@mkdir -p $(TEST_OUT)
	@echo "iniciando testes..."
	@$(MAKE) $(TESTS)
	@echo "acabou os testes"

$(TESTS):
	@echo -n "testando $@: "
	@$(VALGRIND) ./$(TARGET) $(IN_DIR)/$@.txt $(TEST_OUT)/$@.out > $(TEST_OUT)/$@.valgrind \
		&& (diff -q $(TEST_OUT)/$@.out $(OUT_DIR)/$@.out > /dev/null \
			&& echo "✅ passou na lógica e na memória" \
			|| (echo "❌ falhou na lógica"; exit 1)) 
	|| (echo "❌ falha no valgrind"; exit 1)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_OUT)
