#include <iostream>
#include <variant>
#include <string>

#include "simple_ai.hpp"
#include "state.hpp"

void simpleai::initialise() {
    std::cout << "Initialised" << std::endl;
}

int main() {
    simpleai::State testState;
    testState.add("first", 5);
}
