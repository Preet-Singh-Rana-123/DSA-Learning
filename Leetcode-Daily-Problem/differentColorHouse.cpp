#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int> &colors) {
  int n = colors.size();
  int i = 0;
  int j = n - 1;
  int maxDist = 0;

  while (i < n && j >= 0) {
    if (colors[i] != colors[j]) {
      maxDist = max(maxDist, j - i);
      break;
    }
    j--;
  }
  i = 0;
  j = n - 1;
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
