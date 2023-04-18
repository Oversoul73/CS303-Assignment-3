
// CS-303 Assignment 3 - part 2

// 4/17/2023

// Mohammadreza Akbari Lor


// This file contains the main function

#include <iostream>
#include"Queue.h"

using namespace std;

char MainMenu();
// pre:  none
// post: returns the user input for menu to be implemented in the main function

int main() {
    
    Queue test;

    char menuInput;

    // first call of the menu
    menuInput = MainMenu();

    // loop for remaining in menu until Q is selected and executing other commands
    while (menuInput != 'Q') {

        // selecting commad based on user input
        switch (menuInput)
        {
        case 'E':
            int input;

            // prompts for adding input to the queue
            cout << endl;
            cout << "Enter a non-negative integer to be added to the queue: ";
            cin >> input;
            cout << endl;
            test.enqueue(input);
            cout << input << " has been added to the queue." << endl;
            cout << endl;

            break;
        case 'D':
            int temp;

            // prompt for removing input from the queue
            temp = test.dequeue();
            if (temp != -1) {
                cout << endl;
                cout << temp << " has been removed from the queue." << endl;
                cout << endl;
            }

            break;
        case 'P':
            int front;

            // prompt for removing input from the queue
            front = test.peek();
            if (front != -1) {
                cout << endl;
                cout << front << " is at the front of the queue." << endl;
                cout << endl;
            }

            break;
        case 'I':
            if (test.isEmpty()) {
                cout << endl;
                cout << "Yes, the queue is empty!" << endl;
                cout << endl;
            }
            else {
                cout << endl;
                cout << "No, the queue is not empty!" << endl;
                cout << endl;
            }

            break;
        case 'S':
            cout << endl;
            cout << "Size of the queue is " << test.getSize() << endl;
            cout << endl;

            break;
        default:
            cout << endl;
            cout << "Error: Wrong input! Try again!" << endl;
            cout << endl;
            cout << endl;
            break;
        }

        // succesive calls to menu
        menuInput = MainMenu();

    }

    return 0;
}

// function to display menu and get user input for the menu
char MainMenu() {

    char menuInput;

    // printing the menu header and options
    cout << endl;
    cout << "     MENU CHOICES" << endl;
    cout << "E - Enqueue" << endl;
    cout << "D - Dequeue" << endl;
    cout << "P - Peek" << endl;
    cout << "I - Is empty?" << endl;
    cout << "S - Size" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter your choice: ";

    // getting user input for menu
    cin >> menuInput;
    cout << endl;
    menuInput = toupper(menuInput);

    // returning the upper case of inputed letter to main
    switch (menuInput) {
    case 'E':
        return 'E';
        break;
    case 'D':
        return 'D';
        break;
    case 'P':
        return 'P';
        break;
    case 'I':
        return 'I';
        break;
    case 'S':
        return 'S';
        break;
    case 'Q':
        return 'Q';
        break;
    default:
        return 'F';
        break;
    }

}