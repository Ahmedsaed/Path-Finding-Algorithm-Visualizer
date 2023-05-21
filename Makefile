APPLICATION := shortest_path

# Directories 
BUILD_DIR := build
SRC_DIR := sources
INC_DIR := include
OBJ_DIR := objects
TEST_DIR := tests

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
UNIT_TEST_FILES = $(patsubst %.c, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.c)))

# cross-platform compilation
ifeq ($(OS), Windows_NT)
all: windows
else
all: clear_screen build run
endif

build: setup_dirs $(EXECUTABLE)
	@$(MAKE) announce MESSAGE="Compiled successfully"

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} -MMD -c $^ -o $@

-include $(DEPS)

run:
	@./$(EXECUTABLE)

setup_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TEST_DIR/integration)
	@mkdir -p ./$(TEST_DIR/unit)

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