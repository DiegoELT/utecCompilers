#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

bool isInside(const std::string & str, char c);

class Alphabet
{
    char type;
    char value; 
public:
    Alphabet(char value_, std::string alphabetFile);
    char getType();
};

#endif