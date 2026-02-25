#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// You are given two arrays: deadline[], and profit[], which represent a set of
// jobs, where each job is associated with a deadline, and a profit. Each job
// takes 1 unit of time to complete, and only one job can be scheduled at a
// time. You will earn the profit associated with a job only if it is completed
// by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
// -----------------------------------------------------------------------------

bool comp(pair<int, int> &a, pair<int, int> &b) {
  if (a.second != b.second) {
    return a.second > b.second;
  }
  return a.first > b.first;
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
  int n = deadline.size();
  vector<pair<int, int>> jobs(n);
  for (int i = 0; i < n; i++) {
    jobs[i] = {deadline[i], profit[i]};
  }
  sort(jobs.begin(), jobs.end(), comp);

  vector<bool> task(n, 0);
  int count = 0;
  int totalProfit = 0;
  for (int i = 0; i < n; i++) {
    for (int j = jobs[i].first; j > 0; j--) {
      if (!task[j]) {
        task[j] = 1;
        totalProfit += jobs[i].second;
        count++;
        break;
      }
    }
  }
  return {count, totalProfit};
}

int main() {
  vector<int> deadline = {2, 1, 2, 1, 1};
  vector<int> profit = {100, 19, 27, 25, 15};
  vector<int> ans = jobSequencing(deadline, profit);
  cout << "Jobs done: " << ans[0] << "\n";
  cout << "Total profit: " << ans[1] << "\n";
  return 0;
}
