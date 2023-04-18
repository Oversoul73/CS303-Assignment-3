
// CS-303 Assignment 3 - part 1

// 4/12/2023

// Mohammadreza Akbari Lor


// This file contains the main function


#include<iostream>
#include<string>
#include<stack>
#include"Functions.h"

using namespace std;

int main() {

    string infixExpression;
    cout << "Enter an infix expression (no spaces): ";
    cin >> infixExpression;

    // checking for balanced expression
    if (isBalanced(infixExpression)) {
        string postfixExpression = infixToPostfix(infixExpression); // converting to postfix expression
        cout << "Postfix expression: " << postfixExpression << endl;
    }
    else {
        cout << "Invalid! Unbalanced expression!" << endl;
    }

    return 0;

}