#include <iostream>
#include <string>
#include <exception>
#include <any>
#include <map>

#include "state.h"

namespace simpleai {

    template<typename T> void State::add(std::string key, T value){
        auto search = this->data.find(key);
        if (search == this->data.end()){
            std::any convertedValue;
            convertedValue.emplace(value);
            this->data.insert({key, convertedValue});
        } else {
            throw std::invalid_argument("Key already exists in this state");
        }
    }
}
