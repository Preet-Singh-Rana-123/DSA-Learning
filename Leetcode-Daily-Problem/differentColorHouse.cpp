#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// There are n houses evenly lined up on the street, and each house is
// beautifully painted. You are given a 0-indexed integer array colors of length
// n, where colors[i] represents the color of the ith house.

// Return the maximum distance between two houses with different colors.

// The distance between the ith and jth houses is abs(i - j), where abs(x) is
// the absolute value of x.
// ------------------------------------------------------------------------------
// If we see here we can get that to get max distance for different colors
// houses we have to compare all house with first and last lements.

int maxDistance(vector<int> &colors) {
  int n = colors.size();
  int i = 0;
  int j = n - 1;
  int maxDist = 0;

  // comparing all elements with first, starting from last.
  while (i < n && j >= 0) {
    if (colors[i] != colors[j]) {
      maxDist = max(maxDist, j - i);
      break;
    }
    j--;
  }
  i = 0;
  j = n - 1;
  // comparing all elements with last, starting from first.
  while (i < n && j >= 0) {
    if (colors[i] != colors[j]) {
      maxDist = max(maxDist, j - i);
    }
    i++;
  }
  return maxDist;
}

int main() {
  vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
  cout << "The maximum distance between two houses with different colors: "
       << maxDistance(colors) << "\n";
  return 0;
}
