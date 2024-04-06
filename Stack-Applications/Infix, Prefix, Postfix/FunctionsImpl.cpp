#include "Functions.h"
#include "../../../Data-Structures-cpp/Headers/ArrayStack.h"

bool isOperator(char value)
{
    return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '^');
}
bool isNumber(char value)
{
    return (value == '0' || value == '1' || value == '2' || value == '3' || value == '4' || value == '5' || value == '6' || value == '7' || value == '8' || value == '9');
}
std::string reverseString(const std::string &toReverse)
{
    std::string reversed = toReverse;
    int j = 0;
    for (int i = toReverse.length() - 1; i >= 0; i--)
    {
        reversed[j++] = toReverse[i];
    }

    return reversed;
}
bool isOpenningBracket(char value)
{
    return (value == '(');
}
bool isClosingBracket(char value)
{
    return (value == ')');
}
int getPrecedence(char value)
{
    if (value == '^')
        return (3);
    else if (value == '*' || value == '/' || value == '%')
        return (2);
    else if (value == '+' || value == '-')
        return (1);
    else
        return (-1);
}
std::string infixToPrefix(const std::string &infix)
{
    ArrayStack<char> stack;
    std::string reversedInfix = reverseString(infix);
    std::string prefix = "";
    // int prefixCount = 0;
    for (int scanner = 0; scanner < reversedInfix.length(); scanner++)
    {
        if (isOperator(reversedInfix[scanner]))
        {
            // stack.push(reversedInfix[scanner]);
            while (!stack.isEmpty() && getPrecedence(stack.peek()) > getPrecedence(reversedInfix[scanner]))
            {
                prefix += stack.pop();
            }
            stack.push(reversedInfix[scanner]);
        }
        else if (isNumber(reversedInfix[scanner]))
        {
            // prefix[prefixCount++] = reversedInfix[scanner];
            prefix += reversedInfix[scanner];
        }
        else if (isClosingBracket(reversedInfix[scanner]))
        {
            stack.push(reversedInfix[scanner]);
        }
        else if (isOpenningBracket(reversedInfix[scanner]))
        {
            while (!stack.isEmpty() && !isClosingBracket(stack.peek()))
                // prefix[prefixCount++] = stack.pop();
                prefix += stack.pop();
            if (!stack.isEmpty())
                stack.pop(); // to pop closing bracket.
        }
        else
        {
            std::cout << "The infix is invalid, contains other than operator and numbers.\n";
            return ("");
        }
    }
    while (!stack.isEmpty())
    {
        // if (!isClosingBracket(stack.peek()))
        // {
        //     std::cout << "The infix is invalid, brackets are not balanced. [extra opening bracket]\n";
        //     return ("");
        // }
        // prefix[prefixCount++] = stack.pop();
        prefix += stack.pop();
    }
    return (reverseString(prefix)); // to return reversed prefix, as reversed at start as well.
    // return (prefix);
}
std::string infixToPostfix(const std::string &infix)
{
    std::string postfix = "";
    ArrayStack<char> stack;
    for (int scanner = 0; scanner < infix.length(); scanner++)
    {
        if (isOperator(infix[scanner]))
        {
            while (!stack.isEmpty() && getPrecedence(stack.peek()) >= getPrecedence(infix[scanner]))	// >= for operators with equal precedence.
            {
                postfix += stack.pop();
            }
            stack.push(infix[scanner]);
        }
        else if (isNumber(infix[scanner]))
        {
            postfix += infix[scanner];
        }
        else if (isOpenningBracket(infix[scanner]))
        {
            stack.push(infix[scanner]);
        }
        else if (isClosingBracket(infix[scanner]))
        {
            while (!stack.isEmpty() && !isOpenningBracket(stack.peek()))
                postfix += stack.pop();
            stack.pop();
        }
        else
        {
            std::cout << "The infix is invalid, contains other than operator and numbers.\n";
            return ("");
        }
    }
    while (!stack.isEmpty())
        postfix += stack.pop();

    return postfix;
}
int evaluatePrefix(const std::string &prefix)
{
    int result;
    ArrayStack<int> stack;
    std::string reversedPrefix = reverseString(prefix);
    for (int scanner = 0; scanner < reversedPrefix.length(); scanner++)
    {
        if (isNumber(reversedPrefix[scanner]))
        {
            int numericValue = reversedPrefix[scanner] - '0';
            stack.push(numericValue);
        }
        else if (isOperator(reversedPrefix[scanner]))
        {
            int value1 = stack.pop();
            int value2 = stack.pop();
            switch (reversedPrefix[scanner])
            {
            case '+':
                result = value1 + value2;
                break;
            case '-':
                result = value1 - value2;
                break;
            case '*':
                result = value1 * value2;
                break;
            case '/':
                result = value1 / value2;
                break;
            case '%':
                result = value1 % value2;
                break;
            }
            stack.push(result);
        }
    }

    return result;
}
int evaluatePostfix(const std::string &postfix)
{
    int result;
    ArrayStack<int> stack;
    for (int scanner = 0; scanner < postfix.length(); scanner++)
    {
        if (isNumber(postfix[scanner]))
        {
            int numericValue = postfix[scanner] - '0';
            stack.push(numericValue);
        }
        else if (isOperator(postfix[scanner]))
        {
            int value1 = stack.pop();
            int value2 = stack.pop();
            switch (postfix[scanner])
            {
            case '+':
                result = value2 + value1;
                break;
            case '-':
                result = value2 - value1;
                break;
            case '*':
                result = value2 * value1;
                break;
            case '/':
                result = value2 / value1;
                break;
            case '%':
                result = value2 % value1;
                break;
            }
            stack.push(result);
        }
    }
    return result;
}
