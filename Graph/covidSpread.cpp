#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

// Aterp is the head nurse at a city hospital. City hospital contains R*C number
// of wards and the structure of a hospital is in the form of a 2-D matrix.

// Given a matrix of dimension R*C where each cell in the matrix can have values
// 0, 1, or 2 which has the following meaning: 0: Empty ward 1: Cells have
// uninfected patients 2: Cells have infected patients

// An infected patient at ward [i,j] can infect other uninfected patient at
// indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit
// time. Help Aterp determine the minimum units of time after which there won't
// remain any uninfected patient i.e all patients would be infected. If all
// patients are not infected after infinite units of time then simply return -1.
// ------------------------------------------------------------------------------
// To solve this problem we simply traverse the adj matrix using BFS and for
// nodes that have 2 if their adjacent nodes are 1 then we increase timer and
// make them 2 also beacause now they are also infected.
// Also in start we push all nodes with 2 in the queue.

int r, c;
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool isValid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

int findCovidSpread(vector<vector<int>> &hospital) {
  r = hospital.size();
  c = hospital[0].size();

  queue<pair<int, int>> q;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (hospital[i][j] == 2) {
        q.push({i, j});
      }
    }
  }

  int timer = 0;
  int current_patient;
  while (!q.empty()) {
    timer++;
    current_patient = q.size();
    while (current_patient--) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();

      for (int k = 0; k < 4; k++) {
        int ni = i + row[k];
        int nj = i + col[k];
        if (isValid(ni, nj) && hospital[ni][nj] == 1) {
          hospital[ni][nj] = 2;
          q.push({ni, nj});
        }
      }
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (hospital[i][j] == 1) {
        return -1;
      }
    }
  }

  if (timer == 0) {
    return 0;
  }

  return timer - 1;
}

int main() {
  vector<vector<int>> hospital = {{2, 1, 1}, {1, 1, 0}, {1, 1, 1}};
  cout << "Time to spread: " << findCovidSpread(hospital) << "\n";
  return 0;
}
