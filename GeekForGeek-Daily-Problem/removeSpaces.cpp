#include <iostream>
#include <string>
using namespace std;

// Given a string s, remove all the spaces from the string and return the
// modified string.

string removeSpaces(string &s) {
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      ans += s[i];
    }
  }
  return ans;
}

int main() {
  string s = "g eeks for ge eks";
  cout << "String after removing spaces: " << removeSpaces(s) << "\n";
  return 0;
}
