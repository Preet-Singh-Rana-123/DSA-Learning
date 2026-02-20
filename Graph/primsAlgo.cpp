#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// A Minimum Spanning Tree (MST) is a subset of edges in a connected, weighted
// undirected graph that connects all vertices together with the minimum
// possible total edge weight, containing no cycles. It is used for optimizing
// network design, telecommunications, and image segmentation.
//
// Prim's algorithm is a greedy algorithm used to find a Minimum Spanning Tree
// (MST) for a connected, weighted, and undirected graph It grows a spanning
// tree from an initial arbitrary vertex, adding the least-cost edge connecting
// to a new vertex at each step until all vertices are included

int spanningTreeCost(int V, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  // using priority_queue to get minimum weight node
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  pq.push({0, {0, -1}}); // {weight, node, parent}
  vector<bool> isMst(V, 0);
  vector<int> parentVec(V,
                        -1); // creating parent node to make min spanning tree.
  int cost = 0;

  // just doing BFS according to Prim algorithm
  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second.first;
    int parent = pq.top().second.second;
    pq.pop();

    if (!isMst[node]) {
      isMst[node] = 1;
      cost += weight;
      parentVec[node] = parent;

      for (int i = 0; i < adj[node].size(); i++) {
        if (!isMst[adj[node][i].first]) {
          pq.push({adj[node][i].second, {adj[node][i].first, node}});
        }
      }
    }
  }
  return cost;
}

int main() {
  vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
  cout << "Minimum cost of spanning tree: " << spanningTreeCost(3, edges)
       << "\n";
  return 0;
}
