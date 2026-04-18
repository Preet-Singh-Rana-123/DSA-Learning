#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Given an array arr[] consisting of 0’s and 1’s. A flip operation involves
// changing all 0's to 1's and all 1's to 0's within a contiguous subarray.
// Formally, select a range (l, r) in the array arr[], such that (0 ≤ l ≤ r < n)
// holds and flip the elements in this range.

// Return the maximum number of 1's you can get in the array after doing at most
// 1 flip operation.
// ------------------------------------------------------------------------------
// To solve this problem we have to use kanade algorithm because here we can see
// we have to find max gain or lose of 1 after a flip.
//
// so first we find total ones in original array then,
// By fliping 0 we gain 1 so -> +1
// By fliping 1 we lose 1 so -> -1
//
// Now for every iteration we calculate gain in value and find maxGain.
// For currGain we doing max because when currGain is 0 and val is -1 then
// currGain become -1 but we cannot chose that we we reset currGain for that
// case to 0.

int maxOnes(vector<int> &arr) {
  int n = arr.size();
  int totalOnes = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1)
      totalOnes++;
  }

  int currGain = 0;
  int maxGain = 0;

  for (int i = 0; i < n; i++) {
    int val = arr[i] == 0 ? 1 : -1;

    currGain = max(val, currGain + val);
    maxGain = max(maxGain, currGain);
  }

  return maxGain + totalOnes;
}

int main() {
  vector<int> arr = {1, 0, 0, 1, 0, 0, 1};
  cout << "The maximum number of 1's you can get in the array after doing at "
          "most 1 flip operation: "
       << maxOnes(arr) << "\n";
  return 0;
}
