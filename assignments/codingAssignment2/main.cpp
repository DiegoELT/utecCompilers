#include "../codingAssignment1/automata.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout << "Usage of the identifier/constant validator:\n./main <string to validate> <mode Identifier/Constant>";
        return -1;
    }
    std::string variable = argv[1];
    std::string mode = argv[2];
    std::string automataFile, alphabet, name;
    
    // For the sake of not complicating too much with every character, we just consider the ones that are not digits or special characters, to be chars.
    // Also, we are only considering the basic for for int constants.

    if(mode == "0")
    {
        automataFile = "identifierAutomata.txt";
        alphabet = "identifierAlphabet.txt";
        name = "identifier";
    }
    else
    {
        automataFile = "unoptimizedConstant.txt";
        alphabet = "constantAlphabet.txt";
        name = "constant";
    }
    
    Automata turing;
    turing.loadFromFile(automataFile);
    for (size_t i = 0; i < variable.size(); i++)
    {
        Alphabet character(variable[i], alphabet);
        turing.transition(character.getType());
    }
    if(turing.isAccepted())
        std::cout << "The string is recognized as a " << name << ".\n";
    else
        std::cout << "The string is not recognized as a " << name << ".\n";
    
    if(mode == "1" && turing.isAccepted())
    {
        std::cout << "The type of the constant is: ";
        turing.displayCurrentState();
    }
}