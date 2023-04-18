#pragma once

#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isOperator(char c);
//  pre: a character is given;
//  post: whether the character is an operator or not is returned

bool isOpening(char c);
//  pre: a character is given;
//  post: whether the character is an opening paranthesis or not is returned

bool isClosing(char c);
//  pre: a character is given;
//  post: whether the character is a closing paranthesis or not is returned

bool isBalanced(string e);
//  pre: an infix expression is given;
//  post: whether the expression is balanced is returned

int getPrecedence(char c);
//  pre: a character is given;
//  post: the precedence ranking of the character is returned

string infixToPostfix(string e);
//  pre: a balanced infix expression is given;
//  post: the postfix version of the expression (without parantheses) is returned
