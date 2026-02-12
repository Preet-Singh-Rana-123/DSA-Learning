#include <iostream>
using namespace std;

// DFS traversal is a traversal where we pick one path and traverl all nodes of
// that path and when we visited every node then we backtrack to find any
// remaining unvisited node.

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node) {
  visited[node] = 1;   // making node visited.
  cout << node << " "; // printing data

  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]]) { // visiting node only if it is unvisited.
      dfs(adj, visited,
          adj[node][i]); // backtracking to check any unvisited node.
    }
  }
}

int main() {
  vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
  vector<bool> visited(adj.size(), 0);
  dfs(adj, visited, 0);
  return 0;
}
