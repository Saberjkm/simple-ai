#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <random>
#include <iomanip>

#include "concept.hpp"
#include "state.hpp"

simpleai::State simpleai::State::applyInstruction(simpleai::State originalState, std::string instruction) {
    State returnState;
    if (originalState.size() != 4) { throw std::invalid_argument("Given state isnt defined to specifications"); }

    return returnState;
}

const int minVal = -1000;
const int maxVal = 1000;
const int testAmount = 10;

void randomiseState(simpleai::State& state) {
    if (state.size() != 4) { throw std::invalid_argument("Given state isnt defined to specifications"); }

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(minVal, maxVal);

    int firstVal =  uniform_dist(e1);
    int secondVal = uniform_dist(e1);

    state.replace("First Value", firstVal);
    state.replace("Second Value", secondVal);

    uniform_dist = std::uniform_int_distribution<int>(1, 4);
    switch (uniform_dist(e1)) {
        case 1:
            state.replace("Result", double(firstVal + secondVal));
            break;
        case 2:
            state.replace("Result", double(firstVal - secondVal));
            break;
        case 3:
            state.replace("Result", double(firstVal * secondVal));
            break;
        case 4:
            state.replace("Result", double(firstVal) / double(secondVal));
            break;
        default:
            break;
    }
}

int main() {
    std::vector<std::string> instructions = {"+", "-", "*", "/"};
    simpleai::State::setInstructions(instructions);

    // Initialise main state
    simpleai::State workingState;
    workingState.add<int>("First Value", 0);
    workingState.add<int>("Second Value", 0);
    workingState.add<double>("Result", 0.0);
    workingState.add<int>("Score", 0);

    // Main loop
    for (int i = 0; i < testAmount; i++) {
        randomiseState(workingState);
        std::cout << "First Value: ";
        std::cout << workingState.get<int>("First Value");
        std::cout << ", Second Value: ";
        std::cout << workingState.get<int>("Second Value");
        std::cout << ", Result: ";
        std::cout << std::setprecision(17) << double(workingState.get<double>("Result"));
        std::cout << std::endl;
    }
}
