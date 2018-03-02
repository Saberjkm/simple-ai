CC := g++-7
STD := -std=c++17
IFLAGS := -Iinclude
OBJ_DIR := obj
SRC_DIR := source
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: run

run: $(OBJ_FILES)
	$(CC) $(STD) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(STD) $(IFLAGS) -c -o $@ $< 

test: test_main.o test_state.o state.o
	$(CC) $(STD) test.o test_state.o state.o -o run_test

test_main.o: test/test.cpp
	$(CC) $(STD) -c test/test.cpp

test_state.o: test/test_state.cpp
	$(CC) $(STD) $(IFLAGS) -c test/test_state.cpp

clean:
	rm *.o run run_test
 
