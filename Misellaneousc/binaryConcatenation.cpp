#include <cmath>
#include <iostream>
using namespace std;

// Given an integer n, return the decimal value of the binary string formed by
// concatenating the binary representations of 1 to n in order, modulo 109 + 7.
// ----------------------------------------------------------------------------
// To solve this probelm we do bit manipulation.
// If we observe we can see that to add binary of next no. we have to simply
// make space for the no. we add and then simply add it to current no. For e.g.
// :- 1 -> 1 (1 digit)  --> 1 << 2 = 100 2 -> 10 (2 digit) --> 110 << 2 = 11000
// 3 -> 11 (2 digit) --> 11100 << 3 = 11100000
// 4 -> 100 (3 digit) --> 11100100 << 3 = 11100100000
// 5 -> 101 (3 digit)
// 6 -> 110 (3 digit)
// 7 -> 111 (3 digit)
// 8 -> 1000 (4 digit)
// 9 -> 1001 (4 digit)
//
// To find digit require for next no. we use foumula -> log2(current no.) + 1

int M = 1e9 + 7;

int concatenatedBinary1(int n) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int digit = log2(i) + 1;
    ans = ((ans << digit) % M + i) % M;
  }
  return (int)ans;
}

// In this approach if we se for every 2^n no. the digit count is increasing.
// So, we simply increase digit count when we encounter 2^n no.
// To se if num. is 2^n we use condition that (num & (num-1)) == 0

int concatenatedBinary2(int n) {
  long long ans = 0;
  int digit = 0;
  for (int i = 1; i <= n; i++) {
    if ((i & (i - 1)) == 0) {
      digit++;
    }
    ans = ((ans << digit) % M + i) % M;
  }
  return (int)ans;
}

int main() {
  cout << "decimal value of the binary string formed by concatenating the "
          "binary representations of 1 to 23: "
       << concatenatedBinary2(23) << "\n";
  return 0;
}
