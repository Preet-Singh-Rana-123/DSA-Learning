#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Graph Data Structure is a collection of nodes connected by edges. It's used
// to represent relationships between different entities.
// Graphs can be represented using two methods:-
// 1. Using Adjacency Matrix
// 2. Using Adjacency List

// Using Adjacency Matrix
// Representing undirected weighted Graph
// Time Complexity:- O(V^2)
// Space Complexity:- O(V^2)
// Adding edge:- O(1)
// Removing edge:- O(1)
// Searching edge:- O(1)
void matrixRepresentation() {
  int edges, vertex;
  cin >> vertex >> edges;

  vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

  int u, v, weight;
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> weight;
    adjMat[u][v] = weight;
    adjMat[v][u] = weight;
  }

  // printing the matrix
  for (int i = 0; i < vertex; i++) {
    for (int j = 0; j < vertex; j++) {
      cout << adjMat[i][j] << " ";
    }
    cout << "\n";
  }
}

// Using Adjacency List
// Representing undirected weighted Graph
// Time Complexity:- O(V+E)
// Space Complexity:- O(V+E)
// Adding edge:- O(1)
// Removing edge:- O(V)
// Searching edge:- O(V)
void listReapresentation() {
  int edges, vertex;
  cin >> vertex >> edges;

  vector<pair<int, int>> adjLst[vertex];

  int u, v, weight;
  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> weight;
    adjLst[u].push_back(make_pair(v, weight));
    adjLst[v].push_back(make_pair(u, weight));
  }

  // printing the list
  for (int i = 0; i < vertex; i++) {
    cout << i << "->";
    for (int j = 0; j < adjLst[i].size(); j++) {
      cout << adjLst[i][j].first << "(" << adjLst[i][j].second << ") ";
    }
    cout << "\n";
  }
}

int main() { return 0; }
