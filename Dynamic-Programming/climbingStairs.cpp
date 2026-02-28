#include <iostream>
#include <vector>
using namespace std;

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
// -------------------------------------------------------------------------
// To solve this problem we either go 1 step or 2 step at one time so we simply
// count ways in which we can reach top by recurring on every step.

int climbStairs(int i, int n, vector<int> &dp) {
  if (i == n) {
    return 1;
  }
  if (i > n) {
    return 0;
  }

  if (dp[i] != -1) {
    return dp[i];
  }

  return dp[i] = climbStairs(i + 1, n, dp) + climbStairs(i + 2, n, dp);
}

int main() {
  int n = 12;
  vector<int> dp(n + 2, -1);
  cout << "Ways to climb 12 stairs: " << climbStairs(0, n, dp) << "\n";
  return 0;
}
