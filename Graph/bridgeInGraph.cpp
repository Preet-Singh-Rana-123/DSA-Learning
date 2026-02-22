#include <algorithm>
#include <vector>
using namespace std;

// There are n servers numbered from 0 to n - 1 connected by undirected
// server-to-server connections forming a network where connections[i] = [ai,
// bi] represents a connection between servers ai and bi. Any server can reach
// other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some
// servers unable to reach some other server.

// Return all critical connections in the network in any order.
// --------------------------------------------------------------------------------
// Critical connections here are bridges in given graph.
// To solve this problem we will do DFS traversal in while traversing we will
// asign discoveryTime and low to every node. Discovery time tell us at which
// time the node visited in traversing and Low time tell us that node can
// visited neigh through this discoveryTime node.
//
// So, the condition for having a bridge is discoveryTime[node] < low[neigh].

void DFS(int node, int parent, vector<vector<int>> &adj,
         vector<int> &discoveryTime, vector<int> &low, vector<bool> &visited,
         vector<vector<int>> &bridges, int &count) {
  low[node] = discoveryTime[node] =
      count; // first asigning time of visit to node.
  visited[node] = 1;

  for (int i = 0; i < adj[node].size(); i++) {
    int neigh = adj[node][i];
    if (neigh == parent) {
      continue;
    } else if (visited[neigh]) { // if neigh is visited then update node's low
      low[node] = min(low[node], discoveryTime[neigh]);
    } else {
      count++;
      // doing DFS
      DFS(neigh, node, adj, discoveryTime, low, visited, bridges, count);
      // updating low time of node.
      low[node] = min(low[node], low[neigh]);
      // checking condition for bridge node.
      if (discoveryTime[node] < low[neigh]) {
        vector<int> temp;
        temp.push_back(node);
        temp.push_back(neigh);
        bridges.push_back(temp);
      }
    }
  }
}

vector<vector<int>> bridgeInGraph(int n, vector<vector<int>> &edges) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> visited(n, 0);
  vector<int> discoveryTime(n, 0);
  vector<int> low(n, 0);
  vector<vector<int>> bridges;
  int count = 0;

  DFS(0, -1, adj, discoveryTime, low, visited, bridges, count);

  return bridges;
}

int main() {
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
  vector<vector<int>> bridges = bridgeInGraph(4, edges);
  return 0;
}
