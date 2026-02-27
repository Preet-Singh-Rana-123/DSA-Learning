#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &dp) {
  if (n <= 1) {
    return n;
  }

  if (dp[n] != -1) {
    return dp[n];
  }

  return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
}

int main() {
  vector<int> dp(14, -1);
  cout << "fibonacci no. at 13 place: " << fibonacci(13, dp);
  return 0;
}
