#include "alphabet.h"

bool isAlphanumeric(char character)
{
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9') || (character == '_');
}

Alphabet::Alphabet(char value_)
{
    this -> value = value_; 
    // The type is defined by the value that is entered
    if(isAlphanumeric(this -> value))
        type = 'w';
    else
    {
        switch(value)
        {
            case '@': this -> type = 'a';
                break;
            case '.': this -> type = 'p';
                break;
            default: this -> type = 'o';
        }
    }
}

char Alphabet::getType()
{
    return this -> type;
}