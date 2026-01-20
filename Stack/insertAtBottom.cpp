#include "iostream";
#include <stack>
using namespace std;

// To insert element at the bottom of stack we just simply make another stack
// ans and push given stack top in it. Then we simply pushgiven elemnt. After
// that now given stack is empty due to pop, now we just push ans stack's top in
// given stack and then return it.
stack<int> insertAtBottom(stack<int> s, int x) {
  stack<int> ans;
  while (!s.empty()) {
    ans.push(s.top());
    s.pop();
  }
  ans.push(x);
  while (!ans.empty()) {
    s.push(ans.top());
    ans.pop();
  }
  return ans;
}

int main() {
  stack<int> s;
  s.push(2);
  s.push(5);
  s.push(3);
  s.push(7);
  s.push(1);

  stack<int> ans = insertAtBottom(s, 9);

  return 0;
}
