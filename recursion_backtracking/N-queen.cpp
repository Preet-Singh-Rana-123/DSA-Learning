#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You
// may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.
// ----------------------------------------------------------------------------
// To solve this problem we simply brute force every posible outcome.

bool check(vector<string> &board, int n, int i, int j) {
  int row = i, col = j;
  while (row > -1 && col > -1) {
    // if find queen on position then return false.
    if (board[row][col] == 'Q') {
      return 0;
    }
    row--, col--;
  }
  while (row > -1 && col < n) {
    // if find queen on position then return false.
    if (board[row][col] == 'Q') {
      return 0;
    }
    row--, col++;
  }
  // return true if everything is perfect.
  return 1;
}

void find(int row, int n, vector<vector<string>> &ans, vector<string> &board,
          vector<bool> &coloumn) {
  // base condition where row == n
  if (row == n) {
    ans.push_back(board);
    return;
  }

  // checking for every row using rcursion.
  for (int i = 0; i < n; i++) {
    // checking if we can put next queen in current coloumn or not
    // also checking for diagonal conditions.
    if (!coloumn[i] && check(board, n, row, i)) {
      // making current coloumn 1 so now here we cannot put next queen.
      coloumn[i] = 1;
      // putting queen on the reached position.
      board[row][i] = 'Q';
      find(row + 1, n, ans, board, coloumn);
      // backtracking to previous row and col, so now we have to make coloumn
      // visited and make board empty.
      coloumn[i] = 0;
      board[row][i] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  vector<bool> coloumn(n, 0);

  find(0, n, ans, board, coloumn);

  return ans;
}

int main() {
  vector<vector<string>> ans = solveNQueens(6);
  for (int i = 0; i < 6; i++) {
    cout << "Solution: " << i + 1 << "\n";
    for (int j = 0; j < 6; j++) {
      cout << ans[i][j] << "\n";
    }
  }
  return 0;
}
