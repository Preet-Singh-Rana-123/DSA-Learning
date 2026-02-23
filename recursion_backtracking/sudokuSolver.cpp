#include <iostream>
#include <vector>
using namespace std;

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes
// of the grid. The '.' character indicates empty cells.
// ----------------------------------------------------------------------------
// To solve this problem we simply do brute forv=ce for every 1-9 number on each
// empty block and if we not find it then simply backtrack.

bool check(vector<vector<char>> &board, int c, int row, int col) {
  int num = '0' + c;
  // checking row condition.
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num) {
      return 0;
    }
  }
  // checking for col condition
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == num) {
      return 0;
    }
  }
  // checking for block condition
  int i = (row / 3) * 3;
  int j = (col / 3) * 3;
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      if (board[a + i][b + j] == num) {
        return 0;
      }
    }
  }
  return 1;
}

bool find(vector<vector<char>> &board, int row, int col) {
  if (row == 9) {
    return 1;
  }
  if (col == 9) {
    return find(board, row + 1, 0);
  }
  if (board[row][col] != '.') {
    return find(board, row, col + 1);
  }

  for (int i = 1; i <= 9; i++) {
    if (check(board, i, row, col)) {
      board[row][col] = '0' + i;
      if (find(board, row, col + 1)) {
        return 1;
      }
      board[row][col] = '.';
    }
  }

  return 0;
}

void sudokuSolver(vector<vector<char>> &board) { find(board, 0, 0); }

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  sudokuSolver(board);
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
