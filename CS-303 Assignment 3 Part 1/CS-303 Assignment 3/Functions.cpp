
#include<iostream>
#include<string>
#include<stack>

using namespace std;

// function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// function to check if a character is an opening parentheses
bool isOpening(char c) {
    return (c == '{' || c == '(' || c == '[');
}

// function to check if a character is a closing parentheses
bool isClosing(char c) {
    return (c == '}' || c == ')' || c == ']');
}

// function to check for balanced expressions
bool isBalanced(string e) {
    stack<char> s;

    for (int i = 0; i < e.length(); ++i) {
        if (isOpening(e.at(i))) {
            s.push(e.at(i));
        }
        else if (isClosing(e.at(i))) {
            if (s.empty()) {
                return false;  // unbalanced expression
            }
            char top = s.top();
            s.pop();
            if ((e.at(i) == '}' && top != '{') || (e.at(i) == ')' && top != '(') || (e.at(i) == ']' && top != '[')) {
                return false;  // mismatched expression
            }
        }
    }

    return s.empty();  // balanced expression if stack is empty
}

// function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    return 0;
}

// function to perform infix to postfix conversion
string infixToPostfix(string e) {
    stack<char> s;
    string postfix = "";
    string token = "";

    for (int i = 0; i < e.length(); ++i) {
        if (isOperator(e.at(i))) {
            if (token != "") {
                postfix += token;   // adding token to postfix expression
                token = "";   // resetiing token
            }
            while (!s.empty() && !isOpening(s.top()) && getPrecedence(s.top()) >= getPrecedence(e.at(i))) {
                postfix += s.top();
                s.pop();
            }
            s.push(e.at(i));
        }
        else if (isOpening(e.at(i))) {
            if (token != "") {
                postfix += token;  // adding token to postfix expression
                token = "";  // resetiing token
            }
            s.push(e.at(i));
        }
        else if (isClosing(e.at(i))) {
            if (token != "") {
                postfix += token;  // adding token to postfix expression
                token = "";  // resetiing token
            }
            while (!s.empty() && !isOpening(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // pop the opening parenthesis from the stack
        }
        else {
            token += e.at(i);
        }
    }

    if (token != "") {
        postfix += token;
        token = "";
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}
