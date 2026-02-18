#include <iostream>
#include <vector>
using namespace std;

// The Floyd-Warshall algorithm is a dynamic programming algorithm used to find
// the shortest paths between all pairs of nodes in a weighted graph. It
// efficiently handles directed or undirected graphs with positive or negative
// edge weights, but cannot process graphs with negative cycles. The algorithm
// runs in time, where is the number of vertices.
//
// Floyd-Warshall algo works by getting min of distance from direct route or by
// intermediate route.

const int INF = 100000000;

void floydWrashallAlgo(vector<vector<int>> &edges) {
  int n = edges.size();
  for (int i = 0; i < n; i++) {
    edges[i][i] = 0;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // checking condition for min of direct route or intermediate route.
        if (edges[i][k] < INF && edges[k][j] < INF) {
          edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
        }
      }
    }
  }
}

int main() {
  vector<vector<int>> edges = {{0, 4, INF, 5, INF},
                               {INF, 0, 1, INF, 6},
                               {2, INF, 0, 3, INF},
                               {INF, INF, 1, 0, 2},
                               {1, INF, INF, 4, 0}};

  floydWrashallAlgo(edges);

  for (int i = 0; i < edges.size(); i++) {
    for (int j = 0; j < edges.size(); j++) {
      cout << edges[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
