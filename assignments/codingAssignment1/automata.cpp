#include "automata.h"

Automata::Automata(){};

void Automata::addSymbol(char symbol)
{
    alphabetSymbols.push_back(symbol);
}

void Automata::addState(State newState, std::vector<std::pair<char, State> > transitions)
{
    if (newState.getName() == "")
        newState.setName(std::to_string(this -> states.size())); // If the new state doesn't have a name, it gets renamedd to the amount of states currently in the automata. 
    if (transitions.size() != alphabetSymbols.size())
    {
        std::cout << "The amount of transitions of a state in a DFA must be the same as the alphabet size.\n";
        return;
    }
    else
    {
        for (size_t i = 0; i < transitions.size(); i++)
            transitionFunction[std::make_pair(newState, transitions[i].first)] = transitions[i].second; // Adds the new set of transition functions to the table. 
        states.push_back(newState); // Adds the new state to the list of state.
        currentState = &states[0]; // Every time a new state is added, we must update the current state to be the first from the list of states.
    }
}

void Automata::loadFromFile(std::string filename)
{
    int numberOfStates;
    std::ifstream file(filename); 
    std::string automataAlphabet, line, name_, tempBool;
    bool isEnd_; 

    getline(file, automataAlphabet); // The first line corresponds to the automata alphabet.
    for (size_t i = 0; i < automataAlphabet.size(); i++)
        addSymbol(automataAlphabet[i]);

    getline(file, line);
    numberOfStates = std::stoi(line);
    std::vector<State> statesToAdd;
    std::vector<std::pair<char, State> > stateTransitions;
    // Now we proceed to create the states of the automata.
    for (size_t i = 0; i < numberOfStates; i++)
    {
        getline(file, line);
        std::stringstream ss(line); // Here we add the variables necessary for the new state.
        getline(ss, name_, ',');
        getline(ss, tempBool, ',');
        isEnd_ = std::stoi(tempBool);
        if (name_ == "")
            name_ = std::to_string(i); // If no name, we name it after the order of adding. 
        State tempState(name_, isEnd_); 
        statesToAdd.push_back(tempState);
    }
    for (size_t i = 0; i < numberOfStates; i++)
    {
        for (size_t j = 0; j < automataAlphabet.size(); j++)
        {
            getline(file, line); // Now the line becomes the name of the State that we want to find. 
            State tempState = findState(statesToAdd, line);
            if (tempState.getName() == "")
            {
                std::cout << "One of the states in the transition list wasn't found.\n";
                return;
            }
            stateTransitions.push_back(std::make_pair(automataAlphabet[j], tempState));
        }
        addState(statesToAdd[i], stateTransitions);
        stateTransitions.clear();  
    }
}

void Automata::transition(char element)
{
    if (std::find(alphabetSymbols.begin(), alphabetSymbols.end(), element) == alphabetSymbols.end())
        std::cout << "The element does not form part of this automata's alphabet.\n";
    else
        *currentState = transitionFunction[std::make_pair(*currentState, element)]; 
}

void Automata::detailedTransition(char element)
{
    if (std::find(alphabetSymbols.begin(), alphabetSymbols.end(), element) == alphabetSymbols.end())
        std::cout << "The element does not form part of this automata's alphabet.\n";
    else
    {
        std::cout << "The input is: " << element << "\n";
        transition(element);
        std::cout << "The current state is: ";
        displayCurrentState();
    }
}

void Automata::displayAlphabet()
{
    for (size_t i = 0; i < this -> alphabetSymbols.size(); i++)
        std::cout << alphabetSymbols[i];
    std::cout << "\n";
}

void Automata::displayStates()
{
    for (size_t i = 0; i < states.size(); i++)
        std::cout << states[i].getName() << " ";
}

void Automata::displayCurrentState()
{
    std::cout << currentState -> getName() << "\n";
}

bool Automata::isAccepted()
{
    return currentState -> getEnd(); 
}