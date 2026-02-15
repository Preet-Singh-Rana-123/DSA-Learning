#include <iostream>
using namespace std;

// You are given n courses, labeled from 0 to n - 1 and a 2d array
// prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to
// take course  y first if we want to take course x.

// Find the ordering of courses we should take to complete all the courses.
//-------------------------------------------------------------------------------
// To solve this problem we simply apply khan's algorithm to find topological
// sort of DAG.

vector<int> scheduleTask(vector<vector<int>> adj) {
  vector<int> inDeg(adj.size(), 0);
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      inDeg[adj[i][j]]++;
    }
  }

  int node;
  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < adj.size(); i++) {
    if (inDeg[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    node = q.front();
    q.pop();
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
      inDeg[adj[node][i]]--;
      if (inDeg[adj[node][i]] == 0) {
        q.push(adj[node][i]);
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> tasks = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}};
  int n = 5;
  vector<vector<int>> adj(n);
  int m = tasks.size();

  for (int i = 0; i < m; i++) {
    adj[tasks[i][1]].push_back(tasks[i][0]);
  }

  vector<int> ans = scheduleTask(adj);

  // checking if there is cycle or not
  if (ans.size() != n) {
    cout << "There is cycle in tasks\n";
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
