#include <iostream>
#include <vector>
using namespace std;

// Given an integer array arr[] and a 2D array queries[][]. Each query
// queries[i] = [l, r] represents a subarray ranging from index l to r
// (inclusive). For every query, compute the mean (average) of the elements in
// the specified range, and return the floor value of that mean.

// Return an array where each element corresponds to the result of a query.
// -----------------------------------------------------------------------------
// To solve this problem we use prefixSum as it store sum of its and previous
// values, which make it easier to calculate mean with less time complexity.

vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
  vector<int> ans;
  vector<int> prefixSum(arr.size(), 0);
  prefixSum[0] = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i];
  }

  for (int i = 0; i < queries.size(); i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int sum = 0;
    int len = r - l + 1;
    if (l == 0) {
      sum = prefixSum[r];
    } else {
      sum = prefixSum[r] - prefixSum[l - 1];
    }
    ans.push_back(sum / len);
  }
  return ans;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<vector<int>> queries = {{0, 2}, {1, 3}, {0, 4}};
  vector<int> ans = findMean(arr, queries);
  for (int n : ans) {
    cout << n << " ";
  }
  cout << "\n";
  return 0;
}
