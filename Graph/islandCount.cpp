#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Given a grid of size n*m (n is the number of rows and m is the number of
// columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the
// number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and
// is formed by connecting adjacent lands horizontally or vertically or
// diagonally i.e., in all 8 directions.
//-----------------------------------------------------------------------------
//  To solve this problem we simply make an visited array of grid which kept
//  data of nodes we have visited. Then we simply traverse through the grid and
//  where there is land and its not visited we consider it as island and
//  increase a count by 1.

int r, c;
int row[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int col[8] = {0, 0, -1, 1, 1, -1, 1, -1};

bool isValid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

void bfs(int i, int j, vector<vector<char>> &grid,
         vector<vector<bool>> &visited) {
  queue<pair<int, int>> q;
  q.push({i, j});

  int a, b, na, nb;
  while (!q.empty()) {
    a = q.front().first;
    b = q.front().second;
    q.pop();

    for (int k = 0; k < 8; k++) {
      na = a + row[k];
      nb = b + col[k];
      if (isValid(na, nb) && grid[na][nb] == 'L' && !visited[na][nb]) {
        visited[na][nb] = 1;
        q.push({na, nb});
      }
    }
  }
}

int countIsland(vector<vector<char>> &grid) {
  r = grid.size();
  c = grid[0].size();
  vector<vector<bool>> visited(r, vector<bool>(c, 0));
  int count = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // checking weather node is land or water and is is visited or not.
      // If its land visited then we traverse using BFS and update visited
      // according to connected land to current land. After this we simply
      // increase count by 1.
      if (grid[i][j] == 'L' && !visited[i][j]) {
        bfs(i, j, grid, visited);
        count++;
      }
    }
  }

  return count;
}

int main() {
  vector<vector<char>> grid = {{'L', 'L', 'W', 'W', 'W'},
                               {'W', 'L', 'W', 'W', 'L'},
                               {'L', 'W', 'W', 'L', 'L'},
                               {'W', 'W', 'W', 'W', 'W'},
                               {'L', 'W', 'L', 'L', 'W'}};
  cout << "Total Island are: " << countIsland(grid) << "\n";
  return 0;
}
