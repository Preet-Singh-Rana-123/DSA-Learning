#include <iostream>
using namespace std;

// You are given an integer n.

// Define its mirror distance as: abs(n - reverse(n)) where
// reverse(n) is the integer formed by reversing the digits of n.

// Return an integer denoting the mirror distance of n.

// abs(x) denotes the absolute value of x.
// ----------------------------------------------------------------

int mirrorDistance(int n) {
  int reverse = 0;
  int k = n;
  while (k > 0) {
    reverse = reverse * 10 + k % 10;
    k /= 10;
  }

  return n > reverse ? n - reverse : reverse - n;
}

int main() {
  int n = 25;
  cout << "The mirror distance of n: " << mirrorDistance(n) << "\n";
  return 0;
}
