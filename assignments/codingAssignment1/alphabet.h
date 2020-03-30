#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

bool isAlphanumeric(char character);

class Alphabet
{
    char type;
    char value; 
public:
    Alphabet(char value_);
    char getType();
};

#endif