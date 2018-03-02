//TESTING OF STATE
#include <string>
#include <typeinfo>

#include "catch.hpp"
#include "state.hpp"

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

	WHEN("Getting a changed value") {
		testState.add("test", 5.4);
		testState.replace("test", 'c');
		REQUIRE_NOTHROW(testState.get<char>("test"));
	}

	WHEN("Getting a list of key types") {
		testState.add("one", 1);
		testState.add("two", 'c');
		testState.add("three", 5.4);
		auto testMap = testState.getKeyTypes();
		for (auto item = testMap.begin(); item != testMap.end(); ++item) {
			if (item->first == "one") { REQUIRE (*item->second == typeid(int) ); }
			if (item->first == "two") { REQUIRE (*item->second == typeid(char) ); }
			if (item->first == "three") { REQUIRE (*item->second == typeid(double) ); }
		} 
	}

    // Testing invalid
    WHEN("Adding a duplicate key") {
        testState.add("test",1);
        CHECK_THROWS_WITH(testState.add("test", 2), "Key already exists in this state");
        REQUIRE (testState.size() == 1);
    }

    WHEN("Replacing non-existant item") {
        CHECK_THROWS_WITH(testState.replace("test", 1), "Key doesn't exist in this state");
    }

	WHEN("Getting non-existant value") {
		CHECK_THROWS_WITH(testState.get<int>("test"), "Key doesn't exist in this state");
	}

	WHEN("Removing non-existant item") {
		CHECK_THROWS_WITH(testState.remove("test"), "Key doesn't exist in this state");
	}

	WHEN("Getting key types from empty state") {
		CHECK_THROWS_WITH(testState.getKeyTypes(), "There are no keys in this state");
	}
}
