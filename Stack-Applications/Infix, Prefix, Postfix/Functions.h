#ifndef H_Functions
#define H_Functions

#include <iostream>

bool isOperator(char);
bool isNumber(char);
bool isOpenningBracket(char);
bool isClosingBracket(char);
int getPrecedence(char);
std::string reverseString(const std::string &);
std::string infixToPrefix(const std::string &);
std::string infixToPostfix(const std::string &);
int evaluatePrefix(const std::string &);
int evaluatePostfix(const std::string &);

#include "FunctionsImpl.cpp"

#endif