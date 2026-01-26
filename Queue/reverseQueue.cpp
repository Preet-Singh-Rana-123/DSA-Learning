#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// To reverse queue we simple store its front in stack as stack follow LIFO
// concept then it will store the queue's FIFO in revers order.

void reverseQueue(queue<int> &q) {
  stack<int> st;
  while (!q.empty()) {
    st.push(q.front());
    q.pop();
  }
  while (!st.empty()) {
    q.push(st.top());
    st.pop();
  }
}

void printQueue(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << "\n";
}

int main() {
  queue<int> q;
  q.push(9);
  q.push(3);
  q.push(6);
  q.push(10);
  q.push(1);
  q.push(15);

  printQueue(q);
  reverseQueue(q);
  printQueue(q);

  return 0;
}
