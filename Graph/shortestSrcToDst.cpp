#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum
// number of steps required to reach from (0,0) to (X, Y). Note: You can only
// move left, right, up and down, and only through cells that contain 1.
// ----------------------------------------------------------------------------------------
// To solve this problem we simply use BFS traversal because graph is
// unweighted. So, it will be best to use BFS than dijkstra.

int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};

bool isValid(int i, int j, int N, int M) {
  return i >= 0 && i < N && j >= 0 && j < M;
}

int shortestPath(int N, int M, vector<vector<int>> &adj, int X, int Y) {
  // edge case when we have to find starting node.
  if (X == 0 && Y == 0) {
    return 0;
  }

  // edge case when starting node is 0 then we cannot move anywhere
  if (adj[0][0] == 0) {
    return -1;
  }

  queue<pair<int, pair<int, int>>> q; // queue with pair in pair as value.
  q.push({0, {0, 0}});                // u,v,step

  vector<vector<bool>> visited(N, vector<bool>(M, 0));
  visited[0][0] = 1;

  // simply BFS logic
  while (!q.empty()) {
    int u = q.front().first;
    int v = q.front().second.first;
    int step = q.front().second.second;
    q.pop();

    for (int k = 0; k < 4; k++) {
      int new_u = u + row[k];
      int new_v = v + col[k];
      if (isValid(new_u, new_v, N, M) && adj[new_u][new_v] &&
          !visited[new_u][new_v]) {
        // when node found return step+1 acc to question
        if (new_u == X && new_v == Y) {
          return step + 1;
        }
        visited[new_u][new_v] = 1;
        q.push({new_u, {new_v, step + 1}});
      }
    }
  }
  return -1;
}

int main() {
  vector<vector<int>> adj = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 1, 1}};
  cout << "Shortest distance is: " << shortestPath(3, 4, adj, 2, 3) << "\n";
  return 0;
}
