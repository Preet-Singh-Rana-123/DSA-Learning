#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *pre;

  Node(int value) {
    this->data = value;
    this->next = nullptr;
    this->pre = nullptr;
  }
};

// Deque(Double ended queue):- Its a type of queue where we can preform push and
// pop operations from start. It is used to made stacks and queue efficiently.

class Deque {
  Node *front, *rear;

public:
  Deque() { front = rear = nullptr; }

  void push_front(int x) {
    if (front == nullptr) {
      front = rear = new Node(x);
      return;
    }
    Node *temp = new Node(x);
    temp->next = front;
    front->pre = temp;
    front = temp;
  }

  void push_back(int x) {
    if (front == nullptr) {
      front = rear = new Node(x);
      return;
    }
    Node *temp = new Node(x);
    rear->next = temp;
    temp->pre = rear;
    rear = temp;
  }

  void pop_front() {
    if (front->next == nullptr) {
      delete front;
      front = rear = nullptr;
      return;
    } else if (front == nullptr) {
      cout << "Queue underflow\n";
      return;
    }
    Node *temp = front;
    front = front->next;
    front->pre = nullptr;
    delete temp;
  }

  void pop_back() {
    if (rear->pre == nullptr) {
      delete rear;
      rear = front = nullptr;
      return;
    } else if (rear == nullptr) {
      cout << "Queue Underflow\n";
      return;
    }
    Node *temp = rear;
    rear = rear->pre;
    rear->next = nullptr;
    delete temp;
  }

  int start() {
    if (front == nullptr) {
      return -1;
    }
    return front->data;
  }

  int end() {
    if (front == nullptr) {
      return -1;
    }
    return rear->data;
  }
};
