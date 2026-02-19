#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Given a square chessboard, the initial position of Knight and position of a
// target. Find out the minimum steps a Knight will take to reach the target
// position.If it cannot reach the target position return -1.

// Note: The initial and the target position co-ordinates of Knight have been
// given according to 1-base indexing.
// -----------------------------------------------------------------------
// To solve this problem we simply use BFS traversal and also increasing step
// and once we reach destination we return step.

// movements knight do in chessboard
int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isValid(int i, int j, int n) { return i >= 0 && i < n && j >= 0 && j < n; }

int minStep(vector<int> &knight, vector<int> &target, int n) {
  knight[0]--;
  knight[1]--;
  target[0]--;
  target[1]--;

  if (target[0] == knight[0] && target[1] == knight[1]) {
    return 0;
  }

  queue<pair<int, int>> q;
  q.push({knight[0], knight[1]});
  vector<vector<bool>> visited(n, vector<bool>(n, 0));
  visited[knight[0]][knight[1]] = 1;

  int step = 0;

  while (!q.empty()) {
    int count = q.size();
    while (count--) {
      int u = q.front().first;
      int v = q.front().second;
      q.pop();

      for (int k = 0; k < 8; k++) {
        int new_u = u + row[k];
        int new_v = v + col[k];

        if (isValid(new_u, new_v, n) && !visited[new_u][new_v]) {
          if (target[0] == new_u && target[1] == new_v) {
            return step + 1;
          }
          visited[new_u][new_v] = 1;
          q.push({new_u, new_v});
        }
      }
    }
    step++;
  }
  return -1;
}

int main() {
  vector<int> knight = {4, 5};
  vector<int> target = {1, 1};
  cout << "Steps to reach target: " << minStep(knight, target, 6) << "\n";
  return 0;
}
