#include <iostream>
using namespace std;

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
