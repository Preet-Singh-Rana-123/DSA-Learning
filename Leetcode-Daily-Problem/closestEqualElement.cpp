#include <iostream>
#include <vector>
using namespace std;

// You are given a circular array nums and an array queries.

// For each query i, you have to find the following:

// The minimum distance between the element at index queries[i] and any other
// index j in the circular array, where nums[j] == nums[queries[i]]. If no such
// index exists, the answer for that query should be -1. Return an array answer
// of the same size as queries, where answer[i] represents the result for query
// i.

int findInCircularArray(vector<int> &nums, int target, int startIndex) {
  int minDist = INT_MAX;
  int n = nums.size();

  int step = 1;
  int i = (startIndex + 1) % n;
  while (i != startIndex) {
    if (nums[i] == target) {
      minDist = min(minDist, step);
    }
    step++;
    i = (i + 1) % n;
  }
  step = 1;
  i = (startIndex - 1 + n) % n;
  while (i != startIndex) {
    if (nums[i] == target) {
      minDist = min(minDist, step);
    }
    step++;
    i = (i - 1 + n) % n;
  }

  return (minDist == INT_MAX) ? -1 : minDist;
}
vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
  vector<int> ans;
  for (int i = 0; i < queries.size(); i++) {
    ans.push_back(findInCircularArray(nums, nums[queries[i]], queries[i]));
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
  vector<int> queries = {0, 3, 5};
  vector<int> ans = solveQueries(nums, queries);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
