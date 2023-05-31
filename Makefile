APPLICATION := shortest_path

# Directories
BUILD_DIR := build
SRC_DIR := sources
INC_DIR := include
OBJ_DIR := objects
TEST_DIR := tests
TMP_DIR := .tmp

# Make flags
MAKEFLAGS += -s

# Compiler flags
CC := g++
CFLAGS := -Wall -ggdb3

# Files
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES := $(wildcard $(INC_DIR)/*.h)
OBJECT_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCE_FILES))
DEP_FILES := $(OBJECT_FILES:.o=.d)
EXECUTABLE := $(BUILD_DIR)/$(APPLICATION)

# Tests
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.py,%,$(wildcard $(TEST_DIR)/integration/*.py))
UNIT_TEST_FILES = $(patsubst %.cpp, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.cpp)))

# cross-platform compilation
ifeq ($(OS), Windows_NT)
all: windows
else
all: clear_screen build run_tests check_memory
endif

build: setup_dirs $(EXECUTABLE)
	@$(MAKE) announce MESSAGE="Compiled successfully"

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} -MMD -c $^ -o $@

-include $(DEPS)

run: build
	@./$(EXECUTABLE)

integration_tests: $(INTEGRATION_TESTS_FILES)

$(INTEGRATION_TESTS_FILES): %: $(TEST_DIR)/integration/%.py
	@python $<

unit_tests: $(UNIT_TEST_FILES)

$(UNIT_TEST_FILES): %: $(TEST_DIR)/unit/%.cpp
	$(CC) $(filter-out sources/cli.cpp, $(SOURCE_FILES)) -I${INC_DIR} -I${SRC_DIR} -MMD $< -o $(TMP_DIR)/$@.o
	@if ./$(TMP_DIR)/$@.o 2>&1 >/dev/null; then \
		echo "Test $@ passed"; \
	else \
		echo "Test $@ failed"; \
		./$(TMP_DIR)/$@.o; \
	fi; \

run_tests: setup_dirs
	@$(MAKE) announce MESSAGE="Running unit tests"
	@$(MAKE) -k -j 8 unit_tests
	@$(MAKE) announce MESSAGE="Running integration tests"
	@$(MAKE) -k -j 8 integration_tests

check_memory:
	@$(MAKE) announce MESSAGE="Checking memory leaks"
	(valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes \
	-s --error-exitcode=1 ./$(EXECUTABLE) < $(TEST_DIR)/sample_input.txt > ${TMP_DIR}/all.vg 2>&1)  && \
	(make announce MESSAGE="No memory leaks found" && exit 0) || \
	(echo "Error: memory leak found" && cat ${TMP_DIR}/all.vg && exit 1) \

setup_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TEST_DIR/integration)
	@mkdir -p ./$(TEST_DIR/unit)
	@mkdir -p ./$(TMP_DIR)

announce:
	@echo "------------------------------------------"
	@printf "|%*s%s%*s|\n" $$(expr 20 - $${#MESSAGE} / 2) "" "$(MESSAGE)" $$(expr 20 - $$(($${#MESSAGE} + 1)) / 2) ""
	@echo "------------------------------------------"

windows:
	@git-bash.exe -c "make build run && /usr/bin/bash --login -i"

clear_screen:
	@clear

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)
	rm -rf $(TMP_DIR)
