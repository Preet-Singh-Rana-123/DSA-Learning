#include <iostream>
#include <string>
using namespace std;

// Given a string s, replace all the spaces in the string with '%20'.

string URLify(string &s) {
  string ans = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      ans += "%20";
    } else {
      ans += s[i];
    }
  }
  return ans;
}

int main() {
  string s = "i love programming";
  cout << "URLify String: " << URLify(s) << "\n";
}
