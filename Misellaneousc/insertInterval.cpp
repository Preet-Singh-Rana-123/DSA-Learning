#include <algorithm>
#include <vector>
using namespace std;

// You are given an array of non-overlapping intervals intervals where
// intervals[i] = [starti, endi] represent the start and the end of the ith
// interval and intervals is sorted in ascending order by starti. You are also
// given an interval newInterval = [start, end] that represents the start and
// end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in
// ascending order by starti and intervals still does not have any overlapping
// intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Note that you don't need to modify intervals in-place. You can make a new
// array and return it.
// ------------------------------------------------------------------------
// To solve this problem we simply compare start of newInterval with end of
// intervals[i].

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  int n = intervals.size();
  int i = 0;
  vector<vector<int>> ans;

  // no overlapping condition se simply push intervals to ans.
  while (i < n && newInterval[0] > intervals[i][1]) {
    ans.push_back(intervals[i]);
    i++;
  }

  // condition if newInterval comes at last.
  if (i == n) {
    ans.push_back(newInterval);
    return ans;
  }

  // overlapping condition where we update newInterval start with min of
  // interval[i][start] and newInterval[start] and newInterval end with max of
  // newInterval[end] and interval[i][end].
  while (i < n && newInterval[0] <= intervals[i][1]) {
    newInterval[0] = min(intervals[i][0], newInterval[0]);
    newInterval[1] = max(intervals[i][1], newInterval[1]);
    i++;
  }
  ans.push_back(newInterval);

  // condition when newInterval mergeed in bettween of interval but some
  // interval remaining so push them in ans.
  while (i < n) {
    ans.push_back(intervals[i]);
    i++;
  }

  return ans;
}

int main() {
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};
  vector<vector<int>> mergedInterval = insert(intervals, newInterval);
  return 0;
}
