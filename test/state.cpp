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
    
    WHEN("Getting a value") {
        testState.add("test", 1);
        int testInt = testState.get<int>("test");
        REQUIRE (testInt == 1);
        testInt = 2;
        int testIntTwo = testState.get<int>("test");
        REQUIRE (testIntTwo == 1);
    }
    // Testing invalid
    WHEN("Adding a duplicate key") {
        testState.add("test",1);
        CHECK_THROWS_WITH(testState.add("test", 2), "Key already exists in this state");
        REQUIRE (testState.size() == 1);
    }

    WHEN("Replacing non-existing item") {
        CHECK_THROWS_WITH(testState.replace("test", 1), "Key doesn't exist in this state");
    }
}
