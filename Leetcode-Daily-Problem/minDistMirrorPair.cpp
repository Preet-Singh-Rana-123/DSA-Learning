#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// You are given an integer array nums.

// A mirror pair is a pair of indices (i, j) such that:

// 0 <= i < j < nums.length, and
// reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by
// reversing the digits of x. Leading zeros are omitted after reversing, for
// example reverse(120) = 21. Return the minimum absolute distance between the
// indices of any mirror pair. The absolute distance between indices i and j is
// abs(i - j).

// If no mirror pair exists, return -1.
//----------------------------------------------------------------------------

int reverse(int n) {
  int ans = 0;
  while (n > 0) {
    ans = ans * 10 + n % 10;
    n /= 10;
  }
  return ans;
}

int minMirrorPairDistance(vector<int> &nums) {
  int minDist = INT_MAX;
  unordered_map<int, int> mp;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    // ckecking weather number's reverse exists or not
    // if esist then just find min distance.
    if (mp.count(nums[i])) {
      minDist = min(minDist, i - mp[nums[i]]);
    }
    // storing index of reversve of number
    mp[reverse(nums[i])] = i;
  }
  return minDist == INT_MAX ? -1 : minDist;
}

int minMirrorPairDistance2(vector<int> &nums) {
  int minDist = INT_MAX;
  unordered_map<int, int> mp;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[j] == reverse(nums[i])) {
        minDist = min(minDist, j - i);
      }
    }
  }
  return minDist == INT_MAX ? -1 : minDist;
}

int main() {
  vector<int> nums = {12, 21, 45, 33, 54};
  cout << "Minimum absolute distance between the indices of any mirror pair: "
       << minMirrorPairDistance(nums) << "\n";
  return 0;
}
