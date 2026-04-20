#include <iostream>
using namespace std;

// Given a number n, find the total number of Derangements of elements from 1 to
// n. A Derangement is a permutation of n elements, such that no element appears
// in its original position, i.e., 1 should not be the first element, 2 should
// not be second, etc. For example, [5, 3, 2, 1, 4] is a Derangement of first 5
// elements.

// Note: The answer will always fit into a 32-bit integer.
// ----------------------------------------------------------------------
// Recursive function for Derangement:- (n-1)*(D(n-1) + D(n-2))
// Also for 1 there is no Derangement because 1 is allways at its position.
// For 2 the derangement is always 1

int derangeCount(int n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  return (n - 1) * (derangeCount(n - 1) + derangeCount(n - 2));
}

int main() {
  int n = 6;
  cout << "Derangement of first 6 elements: " << derangeCount(6) << "\n";
  return 0;
}
