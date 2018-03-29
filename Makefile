# Makefile

CC		= g++
CFLAGS		= -Wall -Werror -ansi -pedantic -std=c++17 -c
LDFLAGS		=
LDFLAGS_TEST	= -lgtest -lpthread	

RMCMD		= rm
RMFLAGS		= -rf

ECHO		= echo

EXEC		= rvcalc
OBJS		= calc_basic.o calc.o
CSRC		= calc_basic.cpp calc.cpp

CSRC_MAIN	= main.cpp
OBJS_MAIN	= main.o

EXEC_TEST	= rvcalctest
OBJS_TEST	= test.o
CSRC_TEST	= test.cpp


.PHONY: all test clean

all: $(EXEC)

$(EXEC): $(OBJS_MAIN) $(OBJS) 
	$(ECHO) "Linking files"
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.cpp
	$(ECHO) "Compiling files"
	$(CC) -o $@ $< $(CFLAGS) 

calc_basic.o: calc_basic.cpp
	$(ECHO) "Compiling files"
	$(CC) -o $@ $< $(CFLAGS)

calc.o: calc.cpp
	$(ECHO) "Compiling files"
	$(CC) -o $@ $< $(CFLAGS) 

test.o: test.cpp
	$(ECHO) "Compiling files"
	$(CC) -o $@ $< $(CFLAGS) 

test:	$(EXEC_TEST)
	$(ECHO) "Testing..."
	./$<

$(EXEC_TEST): $(OBJS_TEST) $(OBJS)
	$(ECHO) "Linking test"
	$(CC) -o $@ $^ $(LDFLAGS_TEST) 

clean: 
	$(RMCMD) $(RMFLAGS) $(EXEC) $(OBJS_MAIN) $(OBJS) $(EXEC_TEST) $(OBJS_TEST) 
