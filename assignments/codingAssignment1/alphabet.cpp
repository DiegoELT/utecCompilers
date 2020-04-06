#include "alphabet.h"

bool isInside(const std::string & str, char c)
{
    return str.find(c) != std::string::npos;
}

Alphabet::Alphabet(char value_, std::string alphabetFile)
{
    this -> value = value_; 
    this -> type = 'o'; // Initial type is by default "other"
    // The type is defined by the value that is entered
    std::string line, possibleType, alphabetchars;
    std::ifstream alphabetGeneralization(alphabetFile); 
    while(getline(alphabetGeneralization, line))
    {
        std::stringstream ss(line);
        getline(ss, possibleType, ',');
        getline(ss, alphabetchars, ',');
        if(isInside(alphabetchars, value_))
        {
            this -> type = possibleType[0]; 
            break;
        }       
    }
}

char Alphabet::getType()
{
    return this -> type;
}