#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// Given a string s consisting only of the characters '0', '1' and '2',
// determine the length of the smallest substring that contains all three
// characters at least once.

// If no such substring exists, return -1.
// --------------------------------------------------------------------------

int smallestSubstring(string s) {
  int n = s.size();

  int c0 = 0, c1 = 0, c2 = 0;
  int left = 0;
  int minLen = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      c0++;
    else if (s[i] == '1')
      c1++;
    else
      c2++;

    while (c0 > 0 && c1 > 0 && c2 > 0) {
      minLen = min(minLen, i - left + 1);

      if (s[left] == '0')
        c0--;
      else if (s[left] == '1')
        c1--;
      else
        c2--;

      left++;
    }
  }

  return minLen == INT_MAX ? -1 : minLen;
}

int main() {
  string s = "121100112011112";
  cout << "The length of the smallest substring that contains all three "
          "characters at least once: "
       << smallestSubstring(s) << "\n";
  return 0;
}
