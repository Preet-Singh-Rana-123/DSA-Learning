#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Given a string str, the task is to find the bracket numbers, i.e., for each
// bracket in str, return i if the bracket is the ith opening or closing bracket
// to appear in the string.
// --------------------------------------------------------
// To solve this qustion there will be two cases:-
// 1. if str[i] == '(': in this case we have to increase count of bracket and
// push that count to stack and we also push stack's top to ans vector.
// 2. if str[i] == ')': this means bracket close so now we number it same as
// closeset closing bracket, so for that we first push top of stack to ans to
// show which closing bracket and then we pop that count of closing bracket
// because now its close.
vector<int> printBracketNumber(string str) {
  stack<int> st;
  vector<int> ans;
  int count = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      count++;
      st.push(count);
      ans.push_back(st.top());
    } else if (str[i] == ')') {
      ans.push_back(st.top());
      st.pop();
    }
  }
  return ans;
}

int main() {
  string str = "(aa(bdc))p(dee)";
  vector<int> ans = printBracketNumber(str);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
