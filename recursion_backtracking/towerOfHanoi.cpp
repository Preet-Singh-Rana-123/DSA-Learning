#include <iostream>
using namespace std;

void steps(int n, int start, int dest, int helper) {

  if (n == 1) {
    cout << "move disk " << n << " from " << start << " to " << dest << "\n";
    return;
  }

  steps(n - 1, start, helper, dest);
  cout << "move disk " << n << " from " << start << " to " << helper << "\n";
  steps(n - 1, helper, dest, start);
}

int main() {
  steps(4, 1, 2, 3);
  return 0;
}
