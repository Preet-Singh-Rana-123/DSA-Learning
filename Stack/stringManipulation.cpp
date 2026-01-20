#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Tom is a string freak. He has got sequences of words arr[] to manipulate. If
// in a sequence, two same words come together then Tom destroys each other.
// Find the number of words left in the sequence after this pairwise
// destruction.
// -------------------------------------------------------------------------
// To solve this we simply take a stack and then check if top of stack is equal
// to arr[i] if yes then we pop that element from stack and if not then we push
// that element in stack.
int removeConsecutiveSame(vector<string> &arr) {
  stack<string> s;
  s.push(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == s.top()) {
      s.pop();
    } else {
      s.push(arr[i]);
    }
  }
  return s.size();
}

int main() {
  vector<string> arr = {"ab", "aa", "aa", "bcd", "ab"};
  cout << removeConsecutiveSame(arr);
  return 0;
}
