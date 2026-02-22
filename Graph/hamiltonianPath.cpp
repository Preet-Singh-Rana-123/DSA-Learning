#include <iostream>
#include <vector>
using namespace std;

// Given an undirected graph with n vertices and m edges, your task is to
// determine if a Hamiltonian path exists in the graph.

// A Hamiltonian path is a path in an undirected graph that visits each vertex
// exactly once.

// You are provided the following:

// n: The number of vertices in the graph.
// m: The number of edges in the graph.
// edges[][]: A 2D list where each element edges[i] represents an edge between
// two vertices edges[i][0] and edges[i][1].
// -----------------------------------------------------------------------
// To solve this problem we simply do DFS traversal and check if we have visited
// all nodes only once.

bool DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, int &count,
         int n) {
  visited[node] = 1;
  count++;

  // bse condition where count == no. of nodes
  if (count == n) {
    return 1;
  }

  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]] && DFS(adj[node][i], adj, visited, count, n)) {
      return 1;
    }
  }

  // backtracking visited nodes and count when not found Hamiltonial Path
  visited[node] = 0;
  count--;
  return 0;
}

bool isHamiltonianPath(int n, int m, vector<vector<int>> &edges) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u = edges[i][0] - 1;
    int v = edges[i][1] - 1;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n, 0);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (DFS(i, adj, visited, count, n)) {
      return 1;
    }
  }

  return 0;
}

int main() {
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {2, 4}};
  if (isHamiltonianPath(4, 4, edges)) {
    cout << "Has Hamiltonial Path\n";
  } else {
    cout << "Does not has Hamiltonial Path\n";
  }
  return 0;
}
