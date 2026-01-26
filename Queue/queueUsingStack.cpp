#include <iostream>
#include <stack>
using namespace std;

// Implement a first in first out (FIFO) queue using only two stacks. The
// implemented queue should support all the functions of a normal queue (push,
// peek, pop, and empty).
// ---------------------------------------------------------------------------
// To implement queue using stack we use two stacks 1st one store value that are
// pushed in queue and 2nd one store the value in queue we want to pop and peek.
// For pop and peek we check if stack 2 is empty then we tranfer value from
// stack 1 and then pop and peek them.
// For empty we return true only when both stack's are empty.

class MyQueue {
  stack<int> st1; // for push
  stack<int> st2; // for pop/peek
public:
  bool empty() { return st1.empty() && st2.empty(); }

  void push(int x) { st1.push(x); }

  int pop() {
    if (empty()) {
      return -1;
    }
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }
    int val = st2.top();
    st2.pop();
    return val;
  }

  int peek() {
    if (empty()) {
      return -1;
    }
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }
    return st2.top();
  }
};
