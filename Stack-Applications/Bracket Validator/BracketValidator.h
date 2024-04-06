#ifndef H_BracketValidator
#define H_BracketValidator

#include <string>

bool isOpenningBracket(char bracket);
bool isClosingBracket(char bracket);
bool isValid(const std::string &expression);

#include "BracketValidatorImpl.cpp"

#endif