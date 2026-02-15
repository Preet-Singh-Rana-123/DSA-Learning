#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// You are given a grid[][] of size n*m, where every element is either 'O' or
// 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are
// surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are
// 'X' at locations just below, just above, just left and just right of it.
// ----------------------------------------------------------------------------------------
// To solve this problem we simply travel through boundary and when we found 'O'
// we mark visited as 1 because on boundary there is no way it can surround with
// 'X'. Also at founded node we also perborm BFS to find its connected 'O' to
// get full set of 'O'.

int r, c;
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool isValid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

void bfs(int i, int j, vector<vector<char>> &grid,
         vector<vector<bool>> &visited) {
  queue<pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = 1;

  int a, b, na, nb;
  while (!q.empty()) {
    auto [a, b] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      na = a + row[k];
      nb = b + col[k];
      if (isValid(na, nb) && grid[na][nb] == 'O' && !visited[na][nb]) {
        visited[na][nb] = 1;
        q.push({na, nb});
      }
    }
  }
}

void replace(vector<vector<char>> &grid) {
  r = grid.size();
  c = grid[0].size();
  vector<vector<bool>> visited(r, vector<bool>(c, 0));

  // Traversing boundary and founding node with 'O'
  // After founding we do BFS to make it and its connected 'O' visited.
  for (int i = 0; i < r; i++) {
    if (grid[i][0] == 'O' && !visited[i][0]) {
      bfs(i, 0, grid, visited);
    }
    if (grid[i][c - 1] == 'O' && !visited[i][c - 1]) {
      bfs(i, c - 1, grid, visited);
    }
  }
  for (int i = 0; i < c; i++) {
    if (grid[i][0] == 'O' && !visited[i][0]) {
      bfs(i, 0, grid, visited);
    }
    if (grid[i][r - 1] == 'O' && !visited[i][r - 1]) {
      bfs(i, r - 1, grid, visited);
    }
  }

  // now chainging unvisited node to 'X' and kept visited 'O'
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!visited[i][j]) {
        grid[i][j] = 'X';
      }
    }
  }
}

int main() {
  vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'O', 'X', 'X'},
                               {'X', 'X', 'O', 'O'}};
  cout << "Before:\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
  replace(grid);
  cout << "After:\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
