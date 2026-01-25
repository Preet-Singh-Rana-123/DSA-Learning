#include <iostream>
using namespace std;

// Queue is a data stucture formed using the FCFS(First Come First Serve) logic.
// We can perform mainly 5 operations on queue:-
// 1. push()
// 2. pop()
// 3. isEmpty()
// 4. isFull()
// 5. start()
//
// Originally there is so much memory wastage in queue. So, to overcome that we
// use circular queue.
// Circular Queue is special queue in which if there is empty space in starting
// of array using which queue is implemented then we start pushing value in that
// space and update our front and rear accordingly.

class Queue {
  int *arr;
  int front, rear, size;

public:
  Queue(int n) {
    arr = new int[n];
    size = n;
    front = -1;
    rear = -1;
  }

  bool isEmpty() { return front == -1; }

  bool isFull() { return (rear + 1) % size == front; }

  void push(int x) {
    if (this->isEmpty()) {
      front = 0;
      rear = 0;
      arr[rear] = x;
    } else if (this->isFull()) {
      cout << "Queue Overflow\n";
      return;
    } else {
      rear = (rear + 1) % size;
      arr[rear] = x;
    }
  }

  void pop() {
    if (this->isEmpty()) {
      cout << "Queue Underflow\n";
      return;
    } else if (this->front == this->rear) {
      this->front = -1;
      this->rear = -1;
    } else {
      front = (front + 1) % size;
    }
  }

  int start() {
    if (this->isEmpty()) {
      return -1;
    } else {
      return arr[front];
    }
  }
};
