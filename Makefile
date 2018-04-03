# Makefile
# @author rvarago

# Compiler setup

CC			:= g++
CFLAGS			:= -Wall -Werror -ansi -pedantic -std=c++17 -I./include
LDFLAGS			:= 
LDFLAGS_TEST		:= -lgtest -lpthread	

################################################
# Lib

INC_DIR			:= include
INCS			:= $(wildcard $(INC_DIR)/*.hpp)

################################################
# Production

TARGET_DIR		:= bin
TARGET			:= rvcalc
TARGET_FULLNAME		:= $(TARGET_DIR)/$(TARGET)

MAIN_DIR		:= src
MAIN			:= main.cpp
MAIN_FULLNAME		:= $(MAIN_DIR)/$(MAIN)

################################################
# Test

TEST_TARGET_DIR		:= test_bin
TEST_TARGET		:= rvcalctest
TEST_TARGET_FULLNAME	:= $(TEST_TARGET_DIR)/$(TEST_TARGET)

TEST_DIR		:= test
TEST			:= test.cpp
TEST_FULLNAME		:= $(TEST_DIR)/$(TEST)

################################################
# Commands

MKDIR			:= mkdir
MKDIRFLAGS		:= -p
ECHO			:= echo
RMCMD			:= rm
RMFLAGS			:= -rf

################################################
# Phony

.PHONY: all test clean

################################################
# Rules

all: $(TARGET_FULLNAME)
test: $(TEST_TARGET_FULLNAME)

$(TARGET_FULLNAME): $(MAIN_FULLNAME) $(INCS)
	@$(ECHO) "Compiling and linking files..."
	@$(MKDIR) $(MKDIRFLAGS) $(TARGET_DIR)	
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
	
$(TEST_TARGET_FULLNAME): $(TEST_FULLNAME) $(INCS)
	@$(ECHO) "Compiling and linking test files..."
	@$(MKDIR) $(MKDIRFLAGS) $(TEST_TARGET_DIR)
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS_TEST) 

clean: 
	@$(ECHO) "Cleaning build artifacts"
	@$(RMCMD) $(RMFLAGS) $(TARGET_DIR) $(TEST_TARGET_DIR)
