#include <iostream>
#include <vector>
using namespace std;

// The Bellman-Ford algorithm computes the single-source shortest paths in a
// weighted directed graph, accommodating negative edge weights, unlike
// Dijkstra's algorithm. It works by relaxing all edges (where is the number of
// vertices) iteratively and can detect negative cycles, where a path can
// decrease in weight indefinitely.

vector<int> bellmanFordAlgo(int V, int src, vector<vector<int>> &edges) {
  vector<int> distance(V, 1e8);
  distance[src] = 0;

  // traversing V-1 times
  for (int i = 0; i < V - 1; i++) {

    for (int j = 0; j < edges.size(); j++) {
      int u = edges[j][0];
      int v = edges[j][1];
      int weight = edges[j][2];

      if (distance[u] == 1e8) {
        continue;
      }

      // checking condition of Bellman-Ford algorithm
      if (distance[u] + weight < distance[v]) {
        distance[v] = distance[u] + weight;
      }
    }
  }

  // checking for cycle if any then return -1.
  for (int j = 0; j < edges.size(); j++) {
    int u = edges[j][0];
    int v = edges[j][1];
    int weight = edges[j][2];

    if (distance[u] == 1e8) {
      continue;
    }

    if (distance[u] + weight < distance[v]) {
      return {-1};
    }
  }

  return distance;
}

int main() {
  vector<vector<int>> edges = {
      {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
  vector<int> distance = bellmanFordAlgo(5, 0, edges);
  for (int i = 0; i < distance.size(); i++) {
    cout << distance[i] << " ";
  }
  cout << "\n";
  return 0;
}
