#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Dijkstra's algorithm is a fundamental graph search algorithm used to find the
// shortest path from a single source node to all other nodes in a weighted
// graph.

// --------- METHOD 1 -------------
// To solve this problem we follow the bellow approach:-
// 1. Select the node which in not explored yet and has minimum distance among
// all unexplored node.
// 2. Now we relax the edges:-
//    i. Look at all unexplored nodes.
//    ii. if(distance[neighbour] > distance[node] + weight) then:
//           distance[neighbour] = distance[node] + weight
//
// Time Complexity of this method: O(V^2)
// Space Complexity of this method: O(V)

vector<int> dijkstraAlgo1(int V, int src, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  vector<bool> explored(V, 0);
  vector<int> distance(V, INT_MAX);
  distance[src] = 0;

  int count = V;
  while (count--) {
    int node = -1, value = INT_MAX;
    for (int i = 0; i < V; i++) {
      if (!explored[i] && value > distance[i]) {
        value = distance[i];
        node = i;
      }
    }

    explored[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
      int neighbour = adj[node][i].first;
      int weight = adj[node][i].second;

      if (!explored[neighbour] &&
          distance[neighbour] > distance[node] + weight) {
        distance[neighbour] = distance[node] + weight;
      }
    }
  }

  return distance;
}

int main() {
  vector<vector<int>> edges = {
      {0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
  vector<int> distance = dijkstraAlgo1(5, 0, edges);
  for (int i = 0; i < distance.size(); i++) {
    cout << distance[i] << " ";
  }
  cout << "\n";

  return 0;
}
