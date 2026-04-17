#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Given a string s, determine whether its characters can be rearranged to form
// a palindrome. Return true if it is possible to rearrange the string into a
// palindrome; otherwise, return false.
// -----------------------------------------------------------------------
// simple observation that in palindrom all character have even count or there
// is only one odd count of character.

bool canFormPalindrome(string &s) {
  unordered_map<char, int> mp;
  int oddCount = 0;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }

  for (const auto &[key, value] : mp) {
    // getting count of odd character
    if (value % 2 != 0) {
      oddCount++;
    }
  }

  return oddCount > 1 ? false : true;
}

int main() {
  string s = "geeksogeeks";
  if (canFormPalindrome(s)) {
    cout << "It is possible to rearrange the string into a palindrome.\n";
  } else {
    cout << "It is not possible to rearrange the string into a palindrome.\n";
  }
  return 0;
}
