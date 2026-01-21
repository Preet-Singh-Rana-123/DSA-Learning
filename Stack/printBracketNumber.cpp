#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

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
