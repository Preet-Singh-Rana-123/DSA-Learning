#include <algorithm>
#include <iostream>
using namespace std;

// You are given an array of CPU tasks, each labeled with a letter from A to Z,
// and a number n. Each CPU interval can be idle or allow the completion of one
// task. Tasks can be completed in any order, but there's a constraint: there
// has to be a gap of at least n intervals between two tasks with the same
// label.

// Return the minimum number of CPU intervals required to complete all tasks.
// -------------------------------------------------------------------------------------

int leastInterval(vector<char> &tasks, int n) {
  vector<int> freq(26, 0);
  int count = 0;
  for (int i = 0; i < tasks.size(); i++) {
    freq[tasks[i] - 'A']++;
    count = max(count, freq[tasks[i] - 'A']);
  }

  int ans = (count - 1) * (n + 1);
  for (int i = 0; i < 26; i++) {
    if (freq[i] == count) {
      ans++;
    }
  }

  return ans > tasks.size() ? ans : tasks.size();
}

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << "Minimum number of interval to complete tasks: "
       << leastInterval(tasks, 2) << "\n";
  return 0;
}
