//TESTING OF STATE
#include <string>

#include "catch.hpp"
#include "../source/state.cpp"

SCENARIO( "STATE", "[state]" ) {
    simpleai::State testState;
    
    REQUIRE (testState.size() == 0);

    // Testing valid
    WHEN("Adding a valid item") {
        testState.add("test", 1);
        REQUIRE (testState.size() == 1);
        CHECK (testState.has("test"));
    }

    WHEN("Adding different types") {
        testState.add("testOne", 1);
        testState.add("testTwo", 'c');
        REQUIRE (testState.size() == 2);
        CHECK (testState.has("testOne"));
        CHECK (testState.has("testTwo"));
    }

    WHEN("Replacing a value") {
        testState.add("test", 1);
        testState.replace("test", 'c');
        REQUIRE (testState.size() == 1);
    }

    WHEN("Removing a value") {
        testState.add("test", 1);
        testState.remove("test");
        REQUIRE (testState.size() == 0);
    }

    // Testing invalid
}
