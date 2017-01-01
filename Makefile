# Makefile

OBJ_DIR=obj

C_FILES := $(wildcard *.c) $(wildcard */*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(C_FILES:.c=.o)))

CC=clang
CC_FLAGS = -Wall -O2


$(OBJ_FILES): $(C_FILES)
	@mkdir -p "$(@D)"
	@echo compile "$<" to "$@"
	$(CC) $(CC_FLAGS) -c $< -o $@

renderer: $(OBJ_FILES)
	@echo object files "$(OBJ_FILES)"
	$(CC) -o $@ $^

all: renderer

clean:
	rm -rf $(OBJ_DIR)

info:
	@echo sources: $(C_FILES)
	@echo objects: $(OBJ_FILES)
