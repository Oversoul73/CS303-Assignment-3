
#include<iostream>
#include"Queue.h"

using namespace std;

Node::Node(int data) {
    this->data = data;
    next = nullptr;
}

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

void Queue::enqueue(int data) {
    Node* newNode = new Node(data);

    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "The queue is empty!!!" << endl;
        return -1; // return a sentinel value for empty queue
    }

    Node* temp = front;
    int data = front->data;

    front = front->next;
    delete temp;
    size--;

    return data;
}

int Queue::peek() {
    if (isEmpty()) {
        cout << "The queue is empty!!!" << endl;
        return -1; // return a sentinel value for empty queue
    }

    return front->data;
}

bool Queue::isEmpty() {
    return size == 0;
}

int Queue::getSize() {
    return size;
}
