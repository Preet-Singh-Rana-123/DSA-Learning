#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Given an n x n binary grid, in one step you can choose two adjacent rows of
// the grid and swap them.

// A grid is said to be valid if all the cells above the main diagonal are
// zeros.

// Return the minimum number of steps needed to make the grid valid, or -1 if
// the grid cannot be valid.

// The main diagonal of a grid is the diagonal that starts at cell (1, 1) and
// ends at cell (n, n).
// ------------------------------------------------------------------------------
// To solve this problem we follow some step:-
// 1. Find trailing zeroes for each row so that we have info of where we have to
// swap and where we need not to. Trailing zeroes also tell us that which row
// must come first to make grid valid.
// 2. After that we just have to swap thoes rows where the trailing zeroes are
// less than what needed on that row to make it valid grid.

int minSwaps(vector<vector<int>> &grid) {
  int n = grid.size();
  vector<int> zeroes(n, 0);
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (grid[i][j] == 1) {
        break;
      } else {
        count++;
      }
    }
    zeroes[i] = count;
  }

  int swapCount = 0;
  for (int i = 0; i < n; i++) {
    int needed = n - i - 1;
    int j = i;
    // taking j to row where the trailing zeroes are more than needed.
    while (j < n && zeroes[j] < needed) {
      j++;
    }
    // if there is no row where trailing zeroes more than or equal to needed
    // than just return -1.
    if (j == n) {
      return -1;
    }
    // since j is at point where trailing zeroes are more than needed, then we
    // just have to swap row by its upward jow until we reach i.
    while (j > i) {
      swap(zeroes[j], zeroes[j - 1]);
      swapCount++;
      j--;
    }
  }
  return swapCount;
}

int main() {
  vector<vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
  cout << "the minimum number of steps needed to make the grid valid: "
       << minSwaps(grid) << "\n";
  return 0;
}
