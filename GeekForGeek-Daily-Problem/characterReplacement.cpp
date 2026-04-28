#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Given a string s of length n consisting of uppercase English letters and an
// integer k, you are allowed to perform at most k operations.  In each
// operation, you can change any character of the string to any other uppercase
// English letter.

// Determine the length of the longest substring that can be transformed into a
// string with all identical characters after performing at most k such
// operations.
// -------------------------------------------------------------------------
// To solve this problem we use sliding window protocol.
// Here as we can do only k replacement so we first find window length and
// maxFreq in that length and if difference of window length and maxFreq become
// more means we have to reduce the size of window, by shifting window from left
// to right.

int longestSubstr(string &s, int k) {
  vector<int> freq(26, 0);
  int maxFreq = 0;
  int ans = 0;
  int left = 0;

  for (int i = 0; i < s.size(); i++) {
    freq[s[i] - 'A']++;

    maxFreq = max(maxFreq, freq[s[i] - 'A']);

    while ((i - left + 1) - maxFreq > k) {
      freq[s[left]]--;
      left++;
    }

    ans = max(ans, (i - left + 1));
  }
  return ans;
}

int main() {
  string s = "ADBD";
  int k = 1;
  cout
      << "The longest substring that can be transformed into a string with all "
         "identical characters after performing at most k such operations: "
      << longestSubstr(s, k) << "\n";
  return 0;
}
