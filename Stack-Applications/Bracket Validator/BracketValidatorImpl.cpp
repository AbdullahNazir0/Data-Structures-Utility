#include "BracketValidator.h"
#include "../../Headers/ArrayStack.h"

bool isOpenningBracket(char bracket)
{
    return (bracket == '(' || bracket == '[' || bracket == '{');
}

bool isClosingBracket(char bracket)
{
    return (bracket == ')' || bracket == ']' || bracket == '}');
}

bool isValid(const std::string &expression)
{
    ArrayStack<char> myStack;
    for (int i = 0; i < expression.length(); i++)
    {
        if (isOpenningBracket(expression[i]))
            myStack.push(expression[i]);
        else if (isClosingBracket(expression[i]))
        {
            if (myStack.isEmpty())
                return false;

            if ((myStack.peek() == '(' && expression[i] == ')') ||
                (myStack.peek() == '[' && expression[i] == ']') ||
                (myStack.peek() == '{' && expression[i] == '}'))
                myStack.pop();
            else
                myStack.pop();
        }
    }
    return myStack.isEmpty();
}