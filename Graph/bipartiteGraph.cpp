#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check
// whether the graph is bipartite or not.

// A bipartite graph can be colored with two colors such that no two adjacent
// vertices share the same color. This means we can divide the graph’s vertices
// into two distinct sets where:
//  1. All edges connect vertices from one set to vertices in the other set.
//  2. No edges exist between vertices within the same set.
//  -----------------------------------------------------------------------

// To solve this problem using BFS we simply keep track of color we have given
// to each node while traversing them.
// Conditions we need to check while traversing for bipartite graph:-
// 1. If adjacent nodes color is not fill then we fill color to them taht is
// oposite of current node.
// 2. If color of adjacent node is already filled and its oposite of current
// node then we simply continue.
// 3. If we found that adjacent node have same color then that graph is not
// bipartite.
bool isBipartiteBFS(vector<vector<int>> &adj) {
  vector<int> color(adj.size(), -1);
  queue<int> q;
  int node;
  q.push(0);
  color[0] = 0;

  while (!q.empty()) {
    node = q.front();
    q.pop();

    for (int i = 0; i < adj[node].size(); i++) {
      if (color[adj[node][i]] == -1) { // checking condition 1
        color[adj[node][i]] = !color[node];
      } else if (color[adj[node][i]] == !color[node]) { // checking cond. 2
        continue;
      } else { // last condition
        return 0;
      }
      q.push(adj[node][i]); // pushing adjacent node in queue for BFS
    }
  }
  return 1;
}

int main() {
  vector<vector<int>> edges = {{0, 3}, {1, 2}, {3, 2}, {0, 2}};
  int V = 4;
  vector<vector<int>> adj(V);

  for (auto &e : edges) {
    int u = e[0];
    int v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isBipartiteBFS(adj)) {
    cout << "Its a Bipartite Graph\n";
  } else {
    cout << "Not a Bipartite Graph\n";
  }

  return 0;
}
