#include "Polish.h"

std::string postfixToInfix(std::string string)
{

}

std::string infixToPostfix(std::string string)
{

}

int calculatePostfix(std::string string)
{
    std::stringstream str(string);
    int first, second;
    char oper;
    unsigned int len = string.length();
    std::string a, b, o;

    std::getline(str, a, ' ');
    first = std::stoi(a);
    
    for (unsigned int i = 0; i < len; i++)
    {
        std::getline(str, b, ' ');
        std::getline(str, o, ' ');
    }
}