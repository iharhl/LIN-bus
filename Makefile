#

ifeq ($(shell uname -s),Darwin)
	CXX = clang
else
	CXX = gcc
endif

CXX_FLAGS = -Wall -Wextra -Werror
COMPILE = $(CXX) $(CXX_FLAGS)

BUILD_DIR = build
SRC_DIR = src
TEST_DIR = test
UTILS_DIR = utils

SOURCES = $(wildcard $(SRC_DIR)/*.c)
TARGETS = $(subst $(SRC_DIR),$(BUILD_DIR),$(patsubst %.c,%.o,$(SOURCES)))

all: check main.c $(TARGETS) $(BUILD_DIR)/Logger.o
	$(COMPILE) main.c $(BUILD_DIR)/*.o -o $(BUILD_DIR)/main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c build
	$(COMPILE) -c $< -o $@

# utils
$(BUILD_DIR)/%.o: $(UTILS_DIR)/%.c build
	$(COMPILE) -c $< -o $@

run:
	$(BUILD_DIR)/main

test-build: build
	(cd $(BUILD_DIR) && cmake ..)
	cmake --build ./$(BUILD_DIR) --config Debug --target all --

test-run:
	$(BUILD_DIR)/$(TEST_DIR)/LIN_Bus_gtest_master

build:
	mkdir -p $(BUILD_DIR)

check:
	cppcheck --enable=all \
	--error-exitcode=1 \
	--suppress=unusedFunction \
	--suppress=missingIncludeSystem \
	$(SRC_DIR)/*

clean:
	rm -rf $(BUILD_DIR)/*