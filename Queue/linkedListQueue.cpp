#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int value) {
    this->data = value;
    this->next = nullptr;
  }
};

class Queue {
  Node *front;
  Node *rear;

public:
  Queue() { rear = front = nullptr; }

  bool isEmpty() { return front == nullptr; }

  void push(int x) {
    if (isEmpty()) {
      front = new Node(x);
      rear = front;
    } else {
      rear->next = new Node(x);
      rear = rear->next;
    }
  }

  void pop() {
    if (isEmpty()) {
      cout << "Queue Underflow.\n";
      return;
    } else {
      Node *temp = front;
      front = front->next;
      delete temp;
    }
  }

  int start() {
    if (isEmpty()) {
      return -1;
    } else {
      return front->data;
    }
  }
};
