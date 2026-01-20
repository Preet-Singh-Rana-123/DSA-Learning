#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

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
