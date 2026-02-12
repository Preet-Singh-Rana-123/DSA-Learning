#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Topological sorting for DAG(Directed Acyclic Graph) is a linear ordering of
// vertices such that every directed edge U->V, the vertex U comes brfore V.

// To sort a DAG using DFS we follow simple steps:-
// 1. mark node visited.
// 2. Travers current node's adjacent nodes.
// 3. push the node in stack at last.
//
// We are using stack instead of vector array because we want our stored data in
// reverse order.
void dfsTopo(int node, vector<vector<int>> &adj, stack<int> &st,
             vector<bool> &visited) {
  visited[node] = 1;

  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]]) {
      dfsTopo(adj[node][i], adj, st, visited);
    }
  }
  st.push(node);
}

// Khan's Algorithm is another way to find Topological sort of DAG using BFS.
// In this algo we simply push that node in vector which does not have any
// incoming node, and then we just remove that node from graph and repaeate this
// step.
// Steps follow:-
// 1. Find indegree of all vertex.
// 2. push zero indegree vertec into ans.
// 3. For adjacent node of current node we simply decrease indegree of adjacent
// nodes and push nodes that have 0 indegree
void khanAlgo(vector<vector<int>> &adj) {
  int V = adj.size();
  vector<int> inDeg(V, 0);
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      inDeg[adj[i][j]]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
    if (inDeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (int i = 0; i < adj[node].size(); i++) {
      inDeg[adj[node][i]]--;
      if (inDeg[adj[node][i]] == 0) {
        q.push(adj[node][i]);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

int main() {
  vector<vector<int>> adj = {
      {1, 2}, // 0
      {3},    // 1
      {3},    // 2
      {4},    // 3
      {}      // 4
  };
  vector<bool> visited(adj.size(), 0);
  stack<int> st;
  for (int i = 0; i < adj.size(); i++) {
    if (!visited[i]) {
      dfsTopo(i, adj, st, visited);
    }
  }
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << "\nUsing Khan Algo:\n";
  khanAlgo(adj);
  return 0;
}
