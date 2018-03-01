CC=g++-7
STD=-std=c++17
IFLAGS=-Iinclude

all: run

run: simple_ai.o state.o
	$(CC) $(STD) simple_ai.o state.o -o run

simple_ai.o: source/simple_ai.cpp
	$(CC) $(STD) $(IFLAGS) -c source/simple_ai.cpp

state.o: source/state.cpp
	$(CC) $(STD) $(IFLAGS) -c source/state.cpp

test: test_main.o test_state.o state.o
	$(CC) $(STD) test.o test_state.o state.o -o run_test

test_main.o: test/test.cpp
	$(CC) $(STD) -c test/test.cpp

test_state.o: test/test_state.cpp
	$(CC) $(STD) $(IFLAGS) -c test/test_state.cpp

clean:
	rm *.o run run_test
 
