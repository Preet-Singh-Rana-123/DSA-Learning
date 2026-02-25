#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// You are given n tasks labeled from 0 to n - 1 represented by a 2D integer
// array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the
// i task will be available to process at enqueueTimei and will take
// processingTimei to finish processing.

// You have a single-threaded CPU that can process at most one task at a time
// and will act in the following way:

// If the CPU is idle and there are no available tasks to process, the CPU
// remains idle.
//
// If the CPU is idle and there are available tasks, the CPU will choose the one
// with the shortest processing time. If multiple tasks have the same shortest
// processing time, it will choose the task with the smallest index.
//
// Once a task is started, the CPU will process the entire task without
// stopping.
//
// The CPU can finish a task then start a new one instantly.
//
//  Return the order in which the CPU will process the tasks.
//  ---------------------------------------------------------------------------------------------

vector<int> getOrder(vector<vector<int>> &tasks) {
  int n = tasks.size();
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    tasks[i].push_back(i); // enqueTime,processTime,processId
  }
  sort(tasks.begin(), tasks.end());
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq; // processTime,processId

  int time = 0;
  int i = 0;

  while (i < n || !pq.empty()) {
    while (i < n && time >= tasks[i][0]) {
      pq.push({tasks[i][1], tasks[i][2]});
      i++;
    }

    // condition for empty queue then just jump to enqueTime of next.
    if (pq.empty()) {
      time = tasks[i][0];
    } else {
      ans.push_back(pq.top().second);
      time += pq.top().first;
      pq.pop();
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
  vector<int> order = getOrder(tasks);
  for (int i = 0; i < order.size(); i++) {
    cout << order[i] << " ";
  }
  cout << "\n";
  return 0;
}
