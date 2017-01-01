# Makefile

OBJ_DIR := obj

C_FILES := $(wildcard sources/*.c) $(wildcard sources/*/*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(C_FILES:.c=.o)))

CC=clang
CC_FLAGS = -Wall -O2


all: $(OBJ_FILES)
	$(CC) $(CC_FLAGS) $^ -o renderer

$(OBJ_DIR)/%.o: sources/%.c
	@echo Compile "$@"...
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o: sources/tools/%.c
	@echo Compile "$@"...
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(OBJ_DIR)/%.o: sources/render/%.c
	@echo Compile "$@"...
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(filter %.o,$(C_FILES)): %.o: %.c
	@echo Compile "$<" to "$@"...
	$(CC) $(CC_FLAGS) -c $< -o $@



$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)


.PHONY: info
info:
	@echo sources: $(C_FILES)
	@echo objects: $(OBJ_FILES)

# $(OBJ_FILES): $(C_FILES)
# 	@mkdir -p "$(@D)"
# #	$(CC) $(CC_FLAGS) -c $< -o $@

# renderer: $(OBJ_FILES)
# 	@echo object files "$(OBJ_FILES)"
# #	$(CC) -o $@ $^

# all: renderer

# clean:
# 	rm -rf $(OBJ_DIR)



# OBJDIR := objdir
# OBJS := $(addprefix $(OBJDIR)/,foo.o bar.o baz.o)

# $(OBJDIR)/%.o : %.c
#         $(COMPILE.c) $(OUTPUT_OPTION) $<

# all: $(OBJS)

# $(OBJS): | $(OBJDIR)

# $(OBJDIR):
#         mkdir $(OBJDIR)