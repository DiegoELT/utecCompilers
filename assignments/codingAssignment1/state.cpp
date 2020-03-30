#include "state.h"

State::State(){};

State::State(std::string name_, bool isEnd_)
{
    this -> name = name_;
    this -> isEnd = isEnd_;
}

std::string State::getName()
{
    return this -> name;
}

void State::setName(std::string newName)
{
    this -> name = newName;
}

bool State::getEnd()
{
    return this -> isEnd;
}

bool State::operator<(const State& state2) const
{
    return this -> name > state2.name; 
}

State findState(std::vector<State> arrayOfStates, std::string nameToFind)
{
    for (size_t i = 0; i < arrayOfStates.size(); i++)
    {
        if  (arrayOfStates[i].getName() == nameToFind)
            return arrayOfStates[i];
    }
    State errorState("",0); // A state without a name is considered invalid by the automata. 
    return errorState;
}