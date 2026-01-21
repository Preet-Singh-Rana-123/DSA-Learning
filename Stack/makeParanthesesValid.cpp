#include <iostream>
#include <stack>
using namespace std;

// A parentheses string is valid if and only if:

// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid
// strings, or It can be written as (A), where A is a valid string. You are
// given a parentheses string s. In one move, you can insert a parenthesis at
// any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be
// "(()))" or a closing parenthesis to be "())))". Return the minimum number of
// moves required to make s valid.
//
// ----------------------------------------------------------------------------
// To solve this problem we follow same approach as validParanthases question
// but, this time we just return stack's size because that will be the no. of
// parantheses we have to correct.

int minAddToMakeValid(string s) {
  stack<char> st;
  st.push(s[0]);
  for (int i = 1; i < s.size(); i++) {
    if ((!st.empty()) && (st.top() == '(' && s[i] == ')')) {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }
  return st.size();
}

int main() {
  string s = "()()((";
  cout << minAddToMakeValid(s) << "\n";

  return 0;
}
