#include <iostream>
#include <vector>
using namespace std;

// this problem also solved just like cycle detection in un-directed graph but
// this time we also make node unvisited whenever it is going back to its path.

bool detectCycle(vector<vector<int>> &adj, vector<bool> &path,
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
    if (detectCycle(adj, path, visited, adj[node][i])) {
      return true;
    }
  }
  path[node] = 0;
  return false;
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
    if (visited[i] == 0 && detectCycle(adj, path, visited, i)) {
      flag = true;
    }
  }

  if (flag) {
    cout << "Cycle present\n";
  } else {
    cout << "No cycle\n";
  }
  return 0;
}
