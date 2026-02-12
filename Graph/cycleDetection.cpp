#include <iostream>
#include <vector>
using namespace std;

// To detect cycle in a graph we have to travers the whole tree and if we find
// that we are visiting already visited node again then it means there is cycle.

bool detectCycleDFS(int node, int parent, vector<vector<int>> &adj,
                    vector<bool> &visited) {
  visited[node] = 1; // making the node visited

  for (int i = 0; i < adj[node].size(); i++) {
    // Case for dfs when we return after recursion to traver other adjacent
    // node. In that case we cannot mark it as visiting again.
    if (adj[node][i] == parent) {
      continue;
    }

    // return false if node if already visited
    if (visited[adj[node][i]]) {
      return 1;
    }

    // recursion of dfs with current node as paren and its adjacent node as
    // node.
    if (detectCycleDFS(adj[node][i], node, adj, visited)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  vector<vector<int>> adj = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
  vector<bool> visited(4, 0);
  bool flag = 0;

  for (int i = 0; i < 4; i++) {
    if (!visited[i] && detectCycleDFS(0, -1, adj, visited)) {
      flag = 1;
    }
  }

  if (flag) {
    cout << "There is cycle\n";
  } else {
    cout << "There is no cycle\n";
  }
}
