#pragma once

#include <string>
#include <sstream>

std::string postfixToInfix(std::string string);

std::string infixToPostfix(std::string string);

int calculatePostfix(std::string string);