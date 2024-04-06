#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{

    while (true)
    {

        char choice;
        cout << "Enter 1 to convert infix to prefix.\n"
                "Enter 2 to convert infix to postfix.\n"
                "Enter 3 to evaluate prefix.\n"
                "Enter 4 to evaluate postfix.\n"
                "Enter 0 to exit.\n"
                "You entered: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string infix;
            cout << "Enter the infix, you want to convert to prefix: ";
            cin >> infix;

            cout << "Infix: " << infix << "\n";
            cout << "Converted Prefix: " << infixToPrefix(infix) << "\n";
            cout << "Note: If you see infix as converted prefix, it means that the infix you entered is invalid.\n";
            break;
        }
        case '2':
        {
            string infix;
            cout << "Enter the infix, you want to convert to postfix: ";
            cin >> infix;

            cout << "Infix: " << infix << "\n";
            cout << "Converted Postfix: " << infixToPostfix(infix) << "\n";
            cout << "Note: If you see infix as converted postfix, it means that the infix you entered is invalid.\n";
            break;
        }
        case '3':
        {
            std::string prefix;
            cout << "Enter the prefix, you want to evaluate: ";
            cin >> prefix;

            cout << "Prefix: " << prefix << "\n";
            cout << "Result: " << evaluatePrefix(prefix) << "\n";
            break;
        }
        case '4':
        {
            std::string postfix;
            cout << "Enter the postfix, you want to evaluate: ";
            cin >> postfix;

            cout << "Postfix: " << postfix << "\n";
            cout << "Result: " << evaluatePostfix(postfix) << "\n";
            break;
        }
        case '0':
            exit(0);
        default:
            cout << "Invalid input, please try again.\n";
            break;
        }
    }
}