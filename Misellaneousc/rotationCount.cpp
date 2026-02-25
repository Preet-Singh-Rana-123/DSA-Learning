#include <iostream>
using namespace std;

// Given a lock made up of N different circular rings. Each ring has 0-9 digit
// printed on it. There is only one particular code which can open the lock. You
// can rotate each ring any number of times in either direction. Given the
// random sequence R and the desired sequence D, find the minimum number of
// rotations required to open the lock
// -------------------------------------------------------------------------
// To solve this problem we just do minus unit digit of r and d and add them in
// every iteration.

int rotationCount(int r, int d) {
  int a, b;
  int ans = 0;
  while (r || d) {
    a = r % 10;
    b = d % 10;
    int diff = abs(a - b);
    // here doing 10-diff because we can reach 9->2 in 3 step by backward
    // movement. so we have to check which movement give less step.
    ans += min(diff, 10 - diff);
    r /= 10;
    d /= 10;
  }
  return ans;
}

int main() {
  int r = 2345, d = 5432;
  cout << "Minimum Rotation: " << rotationCount(r, d) << "\n";

  return 0;
}
