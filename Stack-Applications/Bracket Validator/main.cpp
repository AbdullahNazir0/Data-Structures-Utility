#include <iostream>
#include "BracketValidator.h"

using namespace std;

int main()
{

    char choice;
    do
    {
        string expression;
        cout << "Enter the expression to check if it is balanced or not: ";
        getline(cin, expression);

        isValid(expression) ? cout << "balanced expression.\n" : cout << "not balanced.\n";

        cout << "Do you want to check another expression (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
