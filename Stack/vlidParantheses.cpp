#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// ----------------------------------------------------------------------------
// To solve this we just simply make a stack and in that we check if "(" in
// stack pair with ")" in string[i] then that means parantheses are valid and we
// just pop out the "(" from stack, else we just push string[i] in stack. For
// valid parantheses stack needs to be empty.
bool isValid(string str) {
  stack<char> s;
  s.push(str[0]);
  for (int i = 1; i < str.size(); i++) {
    if ((!s.empty()) && ((str[i] == ')' && s.top() == '('))) {
      s.pop();
    } else {
      s.push(str[i]);
    }
  }
  return s.empty();
}

int main() {
  string s = "()()(";
  cout << isValid(s) << "\n";

  return 0;
}
