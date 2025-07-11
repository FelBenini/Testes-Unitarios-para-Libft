# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:09:45 by fbenini-          #+#    #+#              #
#    Updated: 2025/07/11 09:32:05 by fbenini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TEST_FLAGS = -Iinclude -Iunity/src

# Directories
UNITY_DIR = unity/src
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Files
UNITY_SRC = $(UNITY_DIR)/unity.c
TEST_SRC = $(wildcard test/*.c)
LIBFT_SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_EXEC = $(BUILD_DIR)/test_runner

# Default target
all: $(BUILD_DIR) $(TEST_EXEC)
	@./$(TEST_EXEC)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Build test executable
$(TEST_EXEC): $(UNITY_SRC) $(TEST_SRC) $(LIBFT_SRCS)
	@$(CC) $(CFLAGS) $(TEST_FLAGS) $^ -o $@
	@echo "Test executable built"

RESULTS = `tail -n 2 $(BUILD_DIR)/test_results.txt`
PASSED = `grep -s PASS $(BUILD_DIR)/test_results.txt`
FAIL = `grep -s FAIL $(BUILD_DIR)/test_results.txt`

# ANSI color codes
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
NC=\033[0m # No Color

# Run tests
test: $(BUILD_DIR) $(TEST_EXEC)
		@./$(TEST_EXEC) > $(BUILD_DIR)/test_results.txt 2>&1
	@echo "$(BLUE)-----------------------$(NC)"
	@echo "$(GREEN)PASSED:$(NC)"
	@echo "$(GREEN)$(PASSED)$(NC)"
	@echo "$(BLUE)-----------------------$(NC)"
	@echo "$(RED)FAILURES:$(NC)"
	@echo "$(RED)$(FAIL)$(NC)"
	@echo "$(BLUE)-----------------------$(NC)"
	@echo "$(YELLOW)$(RESULTS)$(NC)"
	@echo "$(BLUE)-----------------------$(NC)"

# Clean build artifacts
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete"

.PHONY: all test clean
