#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// You are given two non-increasing 0-indexed integer arrays nums1 and nums2.

// A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j <
// nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance
// of the pair is j - i.

// Return the maximum distance of any valid pair (i, j). If there are no valid
// pairs, return 0.

// An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i <
// arr.length.
//
// -----------------------------------------------------------------------------
// To solve this problem we use tow pointer approach.
// As it is given that both num1 and num2 vector ar non-increasing order.
// Since according to condition nums1[i]<=nums2[j] therefore we move i pointer
// only when nums1[i]>nums2[j].
// Also j will move when we have condition
// nums1[i]<=nums2[j] because we have to max the distance b/w i & j so as i is
// fixed we move j until we get nums1[i]>nums2[j].

int maxDistance(vector<int> &nums1, vector<int> &nums2) {
  int maxDist = 0;
  int i = 0, j = 0;
  int n = nums1.size();
  int m = nums2.size();

  while (i < n && j < m) {
    if (nums1[i] > nums2[j]) {
      i++;
    } else {
      maxDist = max(maxDist, j - i);
      j++;
    }
  }

  return maxDist;
}

int main() {
  vector<int> nums1 = {55, 30, 5, 4, 2};
  vector<int> nums2 = {100, 20, 10, 10, 5};
  cout << "The maximum distance of any valid pair (i,j): "
       << maxDistance(nums1, nums2) << "\n";
  return 0;
}
