#include <iostream>
#include <string>
#include <exception>
#include <any>
#include <map>
#include <functional>

#include "state.hpp"

namespace simpleai {
    std::vector<std::string> State::instructionSet = {};

    void State::remove(std::string key) {
        auto search = this->data.find(key);
        if (search == this->data.end()) {
            // Making it explicitly clear that you didn't remove anything
            throw std::invalid_argument("Key doesn't exist in this state");
        } else {
            data.erase(key);
        }
    }

    std::map<std::string, const std::type_info*> State::getKeyTypes() {
        if (this->size() == 0) {
            throw std::logic_error("There are no keys in this state");
        } else {
            std::map<std::string, const std::type_info*> returnMap;
            for (auto item = this->data.begin(); item != this->data.end(); ++item) {
                const std::type_info* typeData = &item->second.type();
                returnMap.insert(std::make_pair(item->first, typeData));
            }
            return returnMap;
        }
    }
}
