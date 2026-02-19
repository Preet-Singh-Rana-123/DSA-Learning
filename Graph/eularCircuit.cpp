#include <iostream>
#include <vector>
using namespace std;

// An Eulerian Path is a path in graph that visits every edge exactly once. An
// Eulerian Circuit is an Eulerian Path which starts and ends on the same
// vertex. Given an undirected graph with V nodes, and E edges, with adjacency
// list adj, return 2 if the graph contains an eulerian circuit, else if the
// graph contains an eulerian path, return 1, otherwise, return 0.
// ----------------------------------------------------------------------------------
// Conditions for Euler Circuit:-
// 1. Calculate degree of each node.
// 2. All node should have even degree;
// 3. All non-zero degree node should be connected.
//
// Conditions for Euler Path:-
// 1. Calculate degree of each node.
// 2. Zero or two node can have odd degree and remaining have even degree.
// 3. All non-zero degree node should be connected.

void DFS(int node, vector<int> adj[], vector<bool> &visited) {
  visited[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]]) {
      DFS(adj[node][i], adj, visited);
    }
  }
}

int isEulerCircuit(int V, vector<int> adj[]) {
  vector<int> deg(V, 0);
  int oddDeg = 0;
  for (int i = 0; i < V; i++) {
    deg[i] = adj[i].size();
    if (deg[i] % 2 != 0) {
      oddDeg++;
    }
  }

  // if there is odd degree then it cannnot be euler path and euler circuit.
  if (oddDeg != 0 && oddDeg != 2) {
    return 0;
  }

  vector<bool> visited(V, 0);
  for (int i = 0; i < V; i++) {
    if (deg[i]) {
      DFS(i, adj, visited);
      break;
    }
  }

  // checking if all non-zero degree node should be connected.
  for (int i = 0; i < V; i++) {
    if (deg[i] && !visited[i]) {
      return 0;
    }
  }

  // if no odd degree then euler circuit.
  if (oddDeg == 0) {
    return 2;
  } else {
    return 1;
  }
}
