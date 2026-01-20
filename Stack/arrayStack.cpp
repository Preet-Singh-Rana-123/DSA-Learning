#include <iostream>
using namespace std;

// Stack is a data stucture that follow LIFO(last-in-first-out) concept.
// We can perform five operations on stack:-> push, pop, peek, isEmpty, isSize.
// There are two prominent conditions that occur in stack:-
// 1. Stack Overflow: In this when user tries to push element in stack when its
// size is already full.
// 2. Stack Underflow: In this when user tries to pop element from stack when
// there are no elementin stack.
class Stack {
  int *arr;
  int top;
  int size;

public:
  Stack(int s) {
    this->top = -1;
    this->size = s;
    this->arr = new int[s];
  }

  // Push is used to put element on top of stack.
  void push(int value) {
    if (top == this->size - 1) {
      cout << "Stack Overflow\n";
      return;
    } else {
      this->top++;
      arr[top] = value;
    }
  }

  // Pop is used when we want to remove element from top.
  void pop() {
    if (this->top == -1) {
      cout << "Stack Underflow\n";
      return;
    } else {
      this->top--;
    }
  }

  // Peek is used to see top element of stack.
  int peek() {
    if (this->top == -1) {
      cout << "Stack Underflow\n";
      return -1;
    } else {
      return arr[this->top];
    }
  }

  // isEmpty used to check weather stack is empty or not.
  bool isEmpty() { return this->top == -1; }

  // isSize used to see elements present in stack.
  // Note: It is not used to see size which stack can hold.
  int isSize() { return this->top + 1; }
};
