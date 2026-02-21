#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning
// Tree (MST) of a connected, weighted, undirected graph by finding a subset of
// edges that connects all vertices with the minimum total weight, without
// cycles. It works by sorting all edges in ascending order of weight and
// iteratively adding the smallest edge, provided it does not form a cycle.
//
// Time Complexity: O(ElogV) or O(ElogV)

int findParent(int u, vector<int> &parent) {
  if (u == parent[u]) {
    return u;
  }
  return parent[u] = findParent(parent[u], parent); // path compression
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank) {
  int pu = findParent(u, parent);
  int pv = findParent(v, parent);

  // merging disjoint tree based on their rank
  if (rank[pu] > rank[pv]) {
    parent[pv] = pu;
  } else if (rank[pv] > rank[pu]) {
    parent[pu] = pv;
  } else {
    // case where both have same rank so we simply merge anyone and increase its
    // rank.
    parent[pv] = pu;
    rank[pu]++;
  }
}

int spanningTreeCost(int V, vector<vector<int>> &edges) {
  // using priority_queue to get minimum weight node
  // priority_queue {w, {u,v}}
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;

  for (int i = 0; i < edges.size(); i++) {
    pq.push({edges[i][2], {edges[i][0], edges[i][1]}});
  }

  vector<int> parent(V);  // parent help us to determine set
  vector<int> rank(V, 0); // rank help us to merge set.
  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }

  int cost = 0;
  int edgesUsed = 0;

  while (!pq.empty()) {
    int weight = pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();

    // check if they are in different set
    if (findParent(u, parent) != findParent(v, parent)) {
      cost += weight;
      unionByRank(u, v, parent, rank);
      edgesUsed++;
    }

    // only V-1 edges are present in minimum spanning tree
    if (edgesUsed == V - 1) {
      break;
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
