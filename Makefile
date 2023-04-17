SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
EXEC_NAME := tetris

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC := gcc
CFLAGS := -MMD -MP

.PHONY: clean test

all: $(BIN_DIR)/$(EXEC_NAME)

clean:
	rm $(OBJ_DIR)/* $(BIN_DIR)/$(EXEC_NAME)

run: $(BIN_DIR)/$(EXEC_NAME)
	$(BIN_DIR)/$(EXEC_NAME)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(EXEC_NAME): $(OBJS) $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

-include $(DEPS)
