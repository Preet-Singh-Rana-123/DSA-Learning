#include <iostream>
#include <queue>
#include <utility>
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

bool detectCycleBFS(vector<vector<int>> &adj, vector<bool> &visited) {
  queue<pair<int, int>>
      q; // making queue that store pair of current node and parent node
  visited[0] = 1;
  q.push(make_pair(0, -1));

  while (!q.empty()) {
    int node = q.front().first;    // storing current node
    int parent = q.front().second; // storing parent node
    q.pop();                       // poping out visited node.

    // now visiting connected node of current node
    for (int i = 0; i < adj[node].size(); i++) {
      // case where node checking if its parent node is visited or not
      // In that case we just continue.
      if (adj[node][i] == parent) {
        continue;
      }
      // return false if found already visited node.
      if (visited[adj[node][i]]) {
        return 1;
      }

      visited[adj[node][i]] == 1;            // making current node visited
      q.push(make_pair(adj[node][i], node)); // pushing it into queue
    }
  }
  return 0;
}

int main() {
  vector<vector<int>> adj = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
  vector<bool> visited(4, 0);
  bool flag = 0;

  for (int i = 0; i < 4; i++) {
    if (!visited[i] && detectCycleBFS(adj, visited)) {
      flag = 1;
    }
  }

  if (flag) {
    cout << "There is cycle\n";
  } else {
    cout << "There is no cycle\n";
  }
}
