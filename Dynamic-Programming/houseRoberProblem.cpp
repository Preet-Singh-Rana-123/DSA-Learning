#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security systems
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the
// police.
// ------------------------------------------------------------------------
// If we see it, we just have 2 cases:-
// 1. Rob from current and then not from adjacen one.
// 2. Rob from adjacent one but not from current one.

int robbery(int index, vector<int> &nums, vector<int> &dp) {
  if (index == 0) {
    return nums[0];
  }
  if (index == 1) {
    return max(nums[0], nums[1]);
  }

  if (dp[index] != -1) {
    return dp[index];
  }

  return dp[index] = max(nums[index] + robbery(index - 2, nums, dp),
                         robbery(index - 1, nums, dp));
}

int main() {
  vector<int> nums = {2, 7, 9, 3, 1};
  vector<int> dp(nums.size(), -1);
  cout << "Maximum robbery: " << robbery(nums.size() - 1, nums, dp) << "\n";
  return 0;
}
