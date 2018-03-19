#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <exception>
#include <any>
#include <map>
#include <vector>
#include <functional>

namespace simpleai {
    class State {
        private:
            std::map<std::string, std::any> data;
			static std::vector<std::string> instructionSet; // List of all avaliable instructions for the state
        public:
            const int size() { return data.size(); };
            const bool has(std::string key) { return (data.count(key) > 0); };
			static const void setInstructions(std::vector<std::string> instructions) { instructionSet = std::move(instructions); }

			// Adds a key, value pair to the state
            template<typename T> void add(const std::string& key, T value) {
				auto search = this->data.find(key);
        		if (search == this->data.end()){
            		std::any convertedValue(value);
            		this->data.insert(std::make_pair(key, convertedValue));
        		} else {
            		// Rather than using an option to 'do nothing' with an already existing key insert or returning a bool
            		// I use this to clearly tell the programmer that you shouldnt be doing this
            		throw std::invalid_argument("Key already exists in this state");
        		} 
			}
 
			// Replaces a value associated with the key with a given value
            template<typename T> void replace(const std::string& key, T value) {
				auto search = this->data.find(key);
        		if (search == this->data.end()) {
            		// Making it explicitly clear this is a replace
            		throw std::invalid_argument("Key doesn't exist in this state");
        		} else {
            		std::any convertedValue(value);
            		data.insert_or_assign(key, convertedValue);
        		}
			}

			// Returns a copy of the value with associated key, use replace to alter that value 
            template<typename T> T get(const std::string& key) {
				auto search = this->data.find(key);
       			if (search == this->data.end()) {
            		throw std::invalid_argument("Key doesn't exist in this state"); 
        		} else {
            		return (T(std::any_cast<T>(search->second)));
        		}
			}

			void remove(std::string key); // Removes a value with the associated key
            std::map<std::string, const std::type_info*> getKeyTypes(); // Returns a map of the keys and type id's
			State applyInstruction(State originalState, std::string instruction); // Applys an instruction to a given state:
    };
}
#endif
