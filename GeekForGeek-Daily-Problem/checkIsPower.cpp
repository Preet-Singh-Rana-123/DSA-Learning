#include <iostream>
using namespace std;

// Given two positive integers x and y, determine if y is a power of x. If y is
// a power of x, return true. Otherwise, return false.
// -----------------------------------------------------------------------

bool isPower(int x, int y) {
  // 1 to power anything will be always 1.
  if (x == 1)
    return y == 1 ? true : false;

  // 1 will always power of every no. because x^0 = 1.
  if (y == 1) {
    return true;
  }

  // iterating until y become 1.
  while (y % x == 0) {
    y /= x;
  }

  // if y become 1 its power else not.
  return y == 1 ? true : false;
}

int main() {
  cout << "Is 16 is a power of 2: " << isPower(2, 16) << "\n";
  return 0;
}
