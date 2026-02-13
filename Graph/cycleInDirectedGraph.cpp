#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// this problem also solved just like cycle detection in un-directed graph but
// this time we also make node unvisited whenever it is going back to its path.

bool detectCycleDFS(vector<vector<int>> &adj, vector<bool> &path,
                    vector<bool> &visited, int node) {
  visited[node] = 1;
  path[node] = 1;

  for (int i = 0; i < adj[node].size(); i++) {
    if (path[adj[node][i]]) {
      return true;
    }
    if (visited[adj[node][i]]) {
      continue;
    }
    if (detectCycleDFS(adj, path, visited, adj[node][i])) {
      return true;
    }
  }
  path[node] = 0;
  return false;
}

// Khan algo approach is also easy, we just have to follow khan's algo and find
// ans array and if size of ans array is equal to no. of vertex then there is no
// cycle, else there is cycle.

bool khanAlgoDetectCycle(vector<vector<int>> &adj) {
  vector<int> inDeg(adj.size(), 0);
  queue<int> q;
  vector<int> ans;

  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      inDeg[adj[i][j]]++;
    }
  }

  for (int i = 0; i < adj.size(); i++) {
    if (!inDeg[i]) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
      inDeg[adj[node][i]]--;
      if (inDeg[adj[node][i]] == 0) {
        q.push(adj[node][i]);
      }
    }
  }

  int count = ans.size();

  return adj.size() != count;
}

int main() {
  int V = 4;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
  vector<vector<int>> adj(V);

  for (auto &e : edges) {
    adj[e[0]].push_back(e[1]);
  }
  vector<bool> visited(adj.size(), 0);
  vector<bool> path(adj.size(), 0);
  bool flag = false;
  for (int i = 0; i < adj.size(); i++) {
    if (visited[i] == 0 && detectCycleDFS(adj, path, visited, i)) {
      flag = true;
    }
  }

  bool flag2 = khanAlgoDetectCycle(adj);

  if (flag2) {
    cout << "Cycle present\n";
  } else {
    cout << "No cycle\n";
  }
  return 0;
}
