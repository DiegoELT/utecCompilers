#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "state.h"

class Automata
{
    State* currentState = nullptr;
    std::map<std::pair<State, char>, State> transitionFunction; 
    std::vector<State> states;
    std::vector<char> alphabetSymbols; // This can be later implemented with Templates so it works with different data types, but for now, this works.
public:
    Automata();
    void addSymbol(char symbol);
    void addState(State newState, std::vector<std::pair<char, State> > transitions);
    void loadFromFile(std::string filename); 
    void transition(char element);
    void detailedTransition(char element);
    void displayAlphabet();
    void displayStates();
    void displayCurrentState(); 
    bool isAccepted();
};

#endif