#include <iostream>
using namespace std;

int winner(int n, int k) {
  if (n == 1) {
    return 0;
  }
  return (winner(n - 1, k) + k) % n;
  // here we just change the winner arr according to arr after killing person at
  // k position
}

int main() {
  int result = winner(8, 3);
  cout << result;
  return 0;
}
