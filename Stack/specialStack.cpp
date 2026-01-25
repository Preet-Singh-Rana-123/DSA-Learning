#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

// Implement a class SpecialStack that supports following operations:

// push(x) – Insert an integer x into the stack.
// pop() – Remove the top element from the stack.
// peek() – Return the top element from the stack. If the stack is empty, return
// -1.
// getMin() – Retrieve the minimum element from the stack in O(1) time. If
// the stack is empty, return -1.
// -----------------------------------------------------------------------------
// To solve this problem in O(1) time complexity we can use modoulus(%) operator
// for hasing pushed value and minimum value in single integer. Since we can
// push number b/w 1 to 100, formula for hasing:-
// [ Hashed no. = Original no. * 101 + min(original no. , stack's top % 101) ]

class SpecialStack {
public:
  stack<int> st;

  void push(int x) {
    if (st.empty()) {
      st.push(x * 101 + x);
    } else {
      st.push(x * 101 + min(x, st.top() % 101));
    }
  }
  void pop() { st.pop(); }
  int getMin() { return st.top() % 101; }
  int peek() { return st.top() / 101; }
};

int main() {
  SpecialStack s;
  s.push(5);
  s.push(10);
  s.push(2);
  s.push(16);
  s.push(25);

  cout << "Stacks min: " << s.getMin();
  cout << "\nStacks top: " << s.peek() << "\n";
  return 0;
}
