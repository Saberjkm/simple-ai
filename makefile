CC := g++-7
STD := -std=c++17
IFLAGS := -Iinclude
OBJ_DIR := obj
SRC_DIR := source
TEST_DIR := test
EXAMPLE_DIR := examples
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_FILES)

test: run_test

run_test: $(OBJ_FILES) $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard $(TEST_DIR)/*.cpp))
	$(CC) $(STD) -o $@ $^

$(EXAMPLE_DIR)/%.cpp: $(OBJ_FILES)
	$(CC) $(STD) $(IFLAGS) -c -o $(patsubst $(EXAMPLE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$@) $@
	$(CC) $(STD) -o $* $(OBJ_DIR)/$*.o $^

$(OBJ_DIR)/%.o: */%.cpp
	$(CC) $(STD) $(IFLAGS) -c -o $@ $<  

clean:
	rm obj/* run run_test

