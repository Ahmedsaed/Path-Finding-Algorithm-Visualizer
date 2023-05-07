APPLICATION := shortest_path
BUILD_DIR := build
SRC_DIR := .
INCLUDE_DIR := include
TEST_DIR := tests
TMP_DIR := .tmp
MAKEFLAGS += -s

CC := g++
CFlags := -Wall -ggdb3

SOURCE_FILES = $(wildcard ./sources/*.cpp)
HEADER_FILES = $(wildcard ./include/*.h)
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.py,%,$(wildcard $(TEST_DIR)/integration/*.py))
UNIT_TEST_FILES = $(patsubst %.c, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.c)))

ifeq ($(OS), Windows_NT)
all: windows
else
all: build run
endif

build: setup_dirs
	@${CC} ${CFlags} ${SOURCE_FILES} -o ./${BUILD_DIR}/${APPLICATION}.out -I ${INCLUDE_DIR}
	@$(MAKE) announce MESSAGE="Compiled successfully"

run:
	@./${BUILD_DIR}/${APPLICATION}.out

setup_dirs:
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TMP_DIR)
	@mkdir -p ./$(TEST_DIR/integration)
	@mkdir -p ./$(TEST_DIR/unit)

announce:
	@echo "------------------------------------------"
	@printf "|%*s%s%*s|\n" $$(expr 20 - $${#MESSAGE} / 2) "" "$(MESSAGE)" $$(expr 20 - $$(($${#MESSAGE} + 1)) / 2) ""
	@echo "------------------------------------------"

windows:
	@git-bash.exe -c "make build run && /usr/bin/bash --login -i"
