#include <iostream>
#include <string>
#include <exception>
#include <any>
#include <map>

#include "state.h"

namespace simpleai {

    // Adds the key,value pair into the internal state container
    template<typename T> void State::add(std::string key, T value){
        auto search = this->data.find(key);
        if (search == this->data.end()){
            std::any convertedValue(value);
            this->data.insert({key, convertedValue});
        } else {
            // Rather than using an option to 'do nothing' with an already existing key insert or returning a bool
            // I use this to clearly tell the programmer that you shouldnt be doing this
            throw std::invalid_argument("Key already exists in this state");
        }
    }
}
