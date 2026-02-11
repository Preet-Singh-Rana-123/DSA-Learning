#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// BFS Traversal is level order traversal where one nodes all connected nodes
// that are not visited.
// To implement BFS we required a queue and a array that store data of visited
// nodes.

void bfs(vector<vector<int>> &adj) {
  int v = adj.size();
  queue<int> q;
  vector<bool> visited(v, 0);
  int node;
  q.push(0);      // pushing starting node in queue.
  visited[0] = 1; // making started node visited.
  while (!q.empty()) {
    node = q.front();
    q.pop();             // poping the visited node.
    cout << node << " "; // printing visited node.
    for (int i = 0; i < adj[node].size();
         i++) { // traversing over connected nodes of current node.
      if (!visited[adj[node][i]]) { // if node is not visited then only push it
                                    // into queue and make it visited.
        q.push(adj[node][i]);
        visited[adj[node][i]] = 1;
      }
    }
  }
}

int main() {

  vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
  bfs(adj);

  return 0;
}
