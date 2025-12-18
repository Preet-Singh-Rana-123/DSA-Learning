#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem Statement
// Given a positive integer n. Your task is to generate a string list of all
// n-bit binary numbers where, for any prefix of the number, there are more or
// an equal number of 1's than 0's. The numbers should be sorted in decreasing
// order of magnitude.

void findNBitBinary(int n, vector<string> &ans, string &temp, int zero,
                    int ones) {

  // recursion ending condition
  if (temp.size() == n) {
    ans.push_back(temp);
    return;
  }

  // condition to check that no. of zeros does not exceed than ones while adding
  // 0 on evry condition
  if (zero < ones) {
    // pushing 0 to end and increasing zeros no.
    temp.push_back('0');
    findNBitBinary(n, ans, temp, zero + 1, ones);
    // poping 0 from back after function is completed on last recursive function
    temp.pop_back();
  }

  // pushing 1 to end and increasing zeros no.
  temp.push_back('1');
  findNBitBinary(n, ans, temp, zero, ones + 1);
  // poping 1 from back after function is completed on last recursive function
  temp.pop_back();
}

int main() {

  vector<string> ans;
  string temp;

  findNBitBinary(6, ans, temp, 0, 0);

  for (int i = 0; i < 6; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
