#include <iostream>
#include <string>
#include <vector>
using namespace std;

// function to check wether rat moving in right direction
bool isValid(int i, int j, int n) { return i >= 0 && j >= 0 && j < n && i < n; }

void totalPaths(vector<vector<int>> &maze, int i, int j, int n, string path,
                vector<string> &ans, vector<vector<int>> &visited) {

  // steps of movement for up,down,left,rigth direction
  int rows[] = {-1, 1, 0, 0};
  int cols[] = {0, 0, -1, 1};
  string dir = "UDLR";

  // ending condition when rat reach goal
  if (i == n - 1 && j == n - 1) {
    ans.push_back(path);
    return;
  }

  // making visited 1 when rat come there
  visited[i][j] = 1;

  // mechanism for rat movement as there are mainly 4 direction rat can move and
  // then we get steps and direction from rows,cols,dir variable we declare in
  // first
  for (int k = 0; k < 4; k++) {

    // this condition to check that rat move in only places that in 1 in maze
    // matrix and also check he is moving in non visited places and in valid
    // place
    if (isValid(i + rows[k], j + cols[k], n) &&
        maze[i + rows[k]][j + cols[k]] && !visited[i + rows[k]][j + cols[k]]) {

      path.push_back(dir[k]); // direction push in path that rat follow
      totalPaths(maze, i + rows[k], j + cols[k], n, path, ans,
                 visited); // recursion occurr
      path.pop_back(); // once function get here after whole recursion then rat
                       // bactrack to to find other paths for that the current
                       // path of rat get pop
    }
  }
  visited[i][j] = 0; // making visited place 0 for backtraing
}

int main() {
  vector<vector<int>> maze = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  vector<vector<int>> visited = {
      {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  vector<string> ans;
  string path;
  totalPaths(maze, 0, 0, 4, path, ans, visited);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
