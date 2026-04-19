#include <iostream>
#include <string>
using namespace std;

// Given two strings s and t, return true if s is a subsequence of t, or false
// otherwise.

// A subsequence of a string is a new string that is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (i.e., "ace" is a
// subsequence of "abcde" while "aec" is not).
//------------------------------------------------------------------------------
// To solve this problem we use two pointer approach.
// So when we found match for character we move both i and j pointer.
// When we not, we just move j pointer.
// In return if i become equal to size of subsequence then it is present, else
// not.

bool isSubsequence(string s, string t) {
  int i = 0, j = 0;
  while (i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      j++;
    }
  }

  return i == s.size() ? true : false;
}

int main() {
  string s = "abc";
  string t = "ahbgdc";
  cout << "String 's' is subsequence of String 't': " << isSubsequence(s, t)
       << "\n";
  return 0;
}
