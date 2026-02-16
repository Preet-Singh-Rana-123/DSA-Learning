#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

// Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer
// array(or vector) edges[ ][ ] of length E, where there is a directed edge from
// edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices and if it is
// impossible to reach any vertex, then return -1 for that vertex.
// --------------------------------------------------------------------------------------
// To solve this problem we can not use simple bfs traversal like in unweighted
// graph because there is posibility of getting shortest distance from any other
// path.
// But if we see to graph and we found that visiting of node in topological
// order and traversing in that manner will solve our above problem.

void dfsTopoSort(stack<int> &st, vector<vector<pair<int, int>>> &adj, int node,
                 vector<bool> &visited) {
  visited[node] = 1;

  for (int i = 0; i < adj.size(); i++) {
    if (!visited[adj[node][i].first]) {
      dfsTopoSort(st, adj, adj[node][i].first, visited);
    }
  }
  st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(V);
  for (int i = 0; i < E; i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];
    adj[u].push_back(make_pair(v, weight));
  }

  vector<bool> visited(V, 0);
  stack<int> st;
  dfsTopoSort(st, adj, 0, visited);

  vector<int> distance(V, INT_MAX);
  distance[0] = 0;

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    for (int i = 0; i < adj[node].size(); i++) {
      int neighbour = adj[node][i].first;
      int weight = adj[node][i].second;

      distance[neighbour] = min(distance[neighbour], distance[node] + weight);
    }
  }

  for (int i = 0; i < V; i++) {
    if (distance[i] == INT_MAX) {
      distance[i] = -1;
    }
  }

  return distance;
}

int main() {
  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2},
                               {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
  vector<int> distance = shortestPath(6, 7, edges);
  for (int i = 0; i < distance.size(); i++) {
    cout << distance[i] << " ";
  }
  cout << "\n";

  return 0;
}
