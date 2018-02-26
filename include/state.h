#ifndef STATE_H
#define STATE_H

#include <string>
#include <any>
#include <map>

namespace simpleai {
    class State {
        private:
            std::map<std::string, std::any> data;
        public:
            const int size() { return data.size(); };
            const bool has(std::string key ) { return (data.count(key) > 0); };

            template<typename T> void add(std::string key, T value); // Adds a key, value pair to the state
            template<typename T> void replace(std::string key, T value); // Replaces a value associated with the key with a given value
            void remove(std::string key); // Removes a value with the associated key
            template<typename T> T get(std::string key); // Returns a copy of the value with associated key, use replace to alter that value
            std::map<std::string, const std::type_info*> getKeyTypes(); // Returns a map of the keys and type id's
    };
}
#endif
