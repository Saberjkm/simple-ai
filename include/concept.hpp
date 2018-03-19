#ifndef CONCEPT_H
#define CONCEPT_H

#include <memory>
#include <typeinfo>
#include <string>
#include <array>
#include <vector>

namespace simpleai {
	class State;

	class Concept {

	};
	
	class Idea {

	};

	class Thought {
		private:
		// Static
		// Normal Member
		public:
		// Static
		template<typename F, typename S> static std::vector<Thought> thinkThoughts(std::unique_ptr<F> firstItem, std::unique_ptr<S> secondItem, int abstractionLevel) {
			if (firstItem == nullptr) {
			
			}
			if (secondItem == nullptr) {

			}
			
		}
		// Normal Member
		
			
	};
	auto testEquals(...);
	template<typename T> auto testEquals(T t) -> decltype((t == t), std::true_type()) {}
	
	Idea createIdea(State firstState, State secondState);

}
#endif
