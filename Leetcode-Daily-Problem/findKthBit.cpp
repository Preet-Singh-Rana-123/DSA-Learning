#include <iostream>
#include <string>
using namespace std;

// Given two positive integers n and k, the binary string Sn is formed as
// follows:

// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed
// string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1
// changes to 0).

// For example, the first four strings in the above sequence are:

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
// Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
// ------------------------------------------------------------------------------------------
// Problem is of simple recursion where we just have to follow given formula of
// Si.

void invert(string &s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      s[i] = '0';
    } else {
      s[i] = '1';
    }
  }
}

string reverseString(string s) {
  invert(s);
  reverse(s.begin(), s.end());
  return s;
}

void find(int n, string &s) {
  if (n == 1) {
    s = "0";
    return;
  }
  find(n - 1, s);
  s = s + "1" + reverseString(s);
}

char findKthBit(int n, int k) {
  string s = "";
  find(n, s);
  return s[k - 1];
}

// --------------------------- OPTIMIZED APPROACH
// ----------------------------------- In this approach if we observe we find
// that 1 will always at middle and its right side is always invert reverse of
// its left side.
//
// So we just find total length of string and its mid by that we can easily
// found kth bit.

char findKthBit2(int n, int k) {
  if (n == 1) {
    return '0';
  }

  int len = (1 << n) - 1;
  int mid = (len + 1) / 2;

  if (k == mid) {
    return '1';
  }

  if (k < mid) {
    return findKthBit2(n - 1, k);
  }

  char c = findKthBit2(n - 1, len - k + 1);
  return c == '0' ? '1' : '0';
}

int main() {
  int n = 4;
  cout << "Return the kth bit in Sn: " << findKthBit2(n, 11) << "\n";
  return 0;
}
