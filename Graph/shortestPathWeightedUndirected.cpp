#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// To get the shortest path for weighted undirected graph we will simply use
// dijkastra algorithm and also stored node's parent data in seprate array to
// get the info for path.

vector<int> findPath(int V, int E, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V + 1);
  for (int i = 0; i < E; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];

    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  vector<bool> explored(V + 1, 0);
  vector<int> parent(V + 1, -1);
  vector<int> distance(V + 1, INT_MAX);
  distance[1] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      p;
  p.push({0, 1});

  while (!p.empty()) {
    int node = p.top().second;
    p.pop();
    if (explored[node]) {
      continue;
    }

    explored[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
      int neighbour = adj[node][i].first;
      int weight = adj[node][i].second;

      if (!explored[neighbour] &&
          distance[neighbour] > distance[node] + weight) {
        distance[neighbour] = distance[node] + weight;
        p.push({distance[neighbour], neighbour});
        parent[neighbour] = node;
      }
    }
  }

  vector<int> path;
  if (parent[V] == -1) {
    path.push_back(-1);
    return path;
  }

  // logic to get path from parent vector.
  int dest = V;
  while (dest != -1) {
    path.push_back(dest);
    dest = parent[dest];
  }

  path.push_back(distance[V]);
  reverse(path.begin(), path.end());

  return path;
}

int main() {
  vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4},
                               {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
  vector<int> path = findPath(5, 6, edges);
  for (int i = 0; i < path.size(); i++) {
    cout << path[i] << " ";
  }
  cout << "\n";

  return 0;
}
