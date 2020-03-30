#ifndef STATE_H
#define STATE_H

#include "alphabet.h"

class State
{
    std::string name; // Mainly for debugging purposes, but can also be used to show how the automata progresses.
    bool isEnd; 
public:
    State(); // Is necessary for when adding a State to the transition table.
    State(std::string name_, bool isEnd_);
    std::string getName();
    void setName(std::string newName);
    bool getEnd();
    bool operator<(const State& state2) const; // Used for the internal organization of the transition functions. 
};

State findState(std::vector<State> arrayOfStates, std::string nameToFind); 

#endif