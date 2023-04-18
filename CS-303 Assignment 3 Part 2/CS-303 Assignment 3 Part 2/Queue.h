#pragma once

// Node class for representing elements in the queue
class Node {
public:
    int data;
    Node* next;

    Node(int data);

};

// Queue class
class Queue {
private:
    Node* front; // front pointer
    Node* rear;  // rear pointer
    int size;    // size of the queue

public:
    Queue();

    // inserts a new element at the rear of the queue.
    void enqueue(int data);

    // removes the front element of the queue and returns it.
    int dequeue();

    // returns the front element present in the queue without removing it.
    int peek();

    // checks if the queue is empty
    bool isEmpty();

    // returns the total number of elements present in the queue
    int getSize();

};