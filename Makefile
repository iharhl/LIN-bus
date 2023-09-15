CXX = gcc
CXX_FLAGS = -Wall -Wextra -Werror
COMPILE = $(CXX) $(CXX_FLAGS)

BUILD_DIR = build
SRC_DIR = src

SOURCES = $(wildcard $(SRC_DIR)/*.c)
TARGETS = $(subst $(SRC_DIR),$(BUILD_DIR),$(patsubst %.c,%.o,$(SOURCES)))

all: main.c $(TARGETS)
	$(COMPILE) main.c $(BUILD_DIR)/*.o -o $(BUILD_DIR)/main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c build
	$(COMPILE) -c $< -o $@

run:
	$(BUILD_DIR)/main

build:
	mkdir -p $(BUILD_DIR)

check:
	cppcheck --quiet --enable=all \
	--error-exitcode=1 \
	--suppress=unusedFunction \
	--suppress=missingIncludeSystem \
	$(SRC_DIR)/*

clean:
	rm -rf $(BUILD_DIR)/*