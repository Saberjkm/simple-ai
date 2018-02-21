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

            template<typename T> void add(std::string key, T value);
            template<typename T> void replace(std::string key, T value);
            void remove(std::string key);
            template<typename T> T& get(std::string key);
    };
}
#endif
