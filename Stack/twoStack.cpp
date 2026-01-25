#include <iostream>
using namespace std;

// You are given an array of a fixed size. Your task is to efficiently implement
// two stacks in this single array.

// The following operations must be supported:

// (i) twoStacks : Initialize the data structures and variables to be used to
// implement  2 stacks in one array.
// (ii) push1(x) : pushes element into the first stack.
// (iii) push2(x) : pushes element into the second stack.
// (iv) pop1() : pops an element from the first stack and returns the popped
// element. If the first stack is empty, it should return -1. (v) pop2() : pops
// an element from the second stack and returns the popped element. If the
// second stack is empty, it should return -1.
// ------------------------------------------------------------------------------------
// To implement this we use two pointer apporoach. Where top1 is at start and
// top2 is at end of an array. By doing this we can implement two stacks in one
// array without wasting memory.

class TwoStack {
public:
  int *arr;
  int top1;
  int top2;
  TwoStack() {
    top1 = -1;
    top2 = 100;
    arr = new int[100];
  }

  void push1(int x) {
    if (top1 + 1 == top2) {
      return;
    }
    top1++;
    arr[top1] = x;
  }

  void push2(int x) {
    if (top1 + 1 == top2) {
      return;
    }
    top2--;
    arr[top2] = x;
  }

  void pop1() {
    if (top1 == -1) {
      return;
    }
    top1--;
  }

  void pop2() {
    if (top2 == 100) {
      return;
    }
    top2++;
  }
};
