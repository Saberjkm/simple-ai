#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "concept.hpp"
#include "state.hpp"

simpleai::State simpleai::State::applyInstruction(simpleai::State originalState, std::string instruction) {
	State returnState;
	if (originalState.size() != 4) { throw std::invalid_argument("Given state isnt defined to specifications"); }
	
	return returnState;
}

int main() {
	
}
