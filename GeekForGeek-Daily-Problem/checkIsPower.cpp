#include <iostream>
using namespace std;

bool isPower(int x, int y) {
  if (x == 1)
    return y == 1 ? true : false;

  if (y == 1) {
    return true;
  }

  while (y % x == 0) {
    y /= x;
  }

  return y == 1 ? true : false;
}

int main() {
  cout << "Is 16 is a power of 2: " << isPower(2, 16) << "\n";
  return 0;
}
