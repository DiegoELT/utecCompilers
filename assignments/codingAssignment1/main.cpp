#include "automata.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout << "Usage of the automata validator of emails:\n./emailValidator <email> <mode>\n";
        return -1; 
    }

    std::string email = argv[1];
    bool mode = std::stoi(argv[2]); 

    Automata turing;
    turing.loadFromFile("emailAutomata.txt");

    for (size_t i = 0; i < email.size(); i++)
    {
        Alphabet character(email[i]);
        if(!mode)
            turing.transition(character.getType());
        else
            turing.detailedTransition(character.getType());
    }

    if(turing.isAccepted())
        std::cout << "The email is accepted by the automata.\n";
    else
        std::cout << "The email is not accepted by the automata.\n";
}