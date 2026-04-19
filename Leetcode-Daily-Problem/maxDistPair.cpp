#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
