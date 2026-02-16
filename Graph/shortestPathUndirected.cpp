#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// To get shortest path for each node we will do simple traversal over whole
// graph and mark node visited and for distance of adjacent we simply add
// distance of node + 1.

vector<int> shortestPathBFS(int V, vector<vector<int>> &edges, int src) {
  vector<vector<int>> adj(V);
  for (int i = 0; i < V; i++) {
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
  }

  vector<bool> visited(V, 0);
  vector<int> distance(V, -1);
  queue<int> q;
  q.push(src);
  distance[src] = 0;
  visited[src] = 1;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < adj[node].size(); i++) {
      if (!visited[adj[node][i]]) {
        visited[adj[node][i]] = 1;
        q.push(adj[node][i]);
        distance[adj[node][i]] = distance[node] + 1;
      }
    }
  }

  return distance;
}

int main() {
  vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5},
                               {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};
  vector<int> distance = shortestPathBFS(edges.size(), edges, 0);
  for (int i = 0; i < distance.size(); i++) {
    cout << distance[i] << " ";
  }
  cout << "\n";
  return 0;
}
