#ifndef SIMPLEAI_H
#define SIMPLEAI_H


namespace simpleai {
    class State;

    void initialise();
    void learn(State& initialState);
    State& useInstruction(State& currentState); 
}
#endif


