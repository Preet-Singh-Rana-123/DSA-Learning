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

// In linked-list implementation of stack there is generaly no stack overflow
// condition because linked-list is dynamic in nature. But there is one
// condition for stack overflow that is when we created so big stack that now
// its overflowing ram of device.
class Stack {
  Node *top;
  int size;

public:
  Stack() {
    this->top = nullptr;
    this->size = 0;
  }

  void push(int value) {
    Node *temp = new Node(value);
    temp->next = this->top;
    this->top = temp;
    this->size++;
  }

  void pop() {
    if (this->top == nullptr) {
      cout << "Stack Underflow.\n";
      return;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
    this->size--;
  }

  int peek() {
    if (this->top == nullptr) {
      cout << "Stack is empty.\n";
      return -1;
    } else {
      return this->top->data;
    }
  }

  bool isEmpty() { return this->top == nullptr; }

  int isSize() { return this->size; }
};
