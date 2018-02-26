#include <iostream>
#include <variant>
#include <string>

#include "simple_ai.h"
#include "state.h"

void simpleai::initialise() {
    std::cout << "Initialised" << std::endl;
}

int main() {
    simpleai::State testState;
    testState.add<int>(std::string("one"), 5);
}
