#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Given an array of intervals intervals where intervals[i] = [starti, endi],
// return the minimum number of intervals you need to remove to make the rest of
// the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For
// example, [1, 2] and [2, 3] are non-overlapping.
// -----------------------------------------------------------------------------
// To solve this problem we simply sort the array based on ending intervals and
// then compare starting interval with ending interval of next to find
// Overlapping.

bool comp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

int eraseOverlapIntervals(vector<vector<int>> &intervals) {
  int n = intervals.size();
  sort(intervals.begin(), intervals.end(), comp);

  // storing prev interval ending for comparision for next's start.
  int prevInterval = intervals[0][1];
  int count = 1; // initialy count of Overlapping is 1 becase first one overlapp
                 // with itself.
  for (int i = 1; i < n; i++) {
    if (prevInterval <= intervals[i][0]) {
      prevInterval = intervals[i][1];
      count++;
    }
  }
  return n - count;
}

int main() {
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  cout << "Overlapping intervals are: " << eraseOverlapIntervals(intervals)
       << "\n";
  return 0;
}
