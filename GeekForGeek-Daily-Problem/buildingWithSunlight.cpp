#include <iostream>
#include <vector>
using namespace std;

// Given the array arr[] of heights of certain buildings that lie adjacent to
// each other, Sunlight starts falling from the left side of the buildings. If
// there is a building of a certain height, all the buildings to the right side
// of it having lesser heights cannot see the sun.

// Find the total number of buildings that receive sunlight.
// ----------------------------------------------------------------------------
// For this problem we just have to maintain maxHeight of arr of buildings and
// since if in front there is big then back one then not get light. Also we keep
// updating maxHeight as we found building with more height then maxHeight.

int visibleBuildings(vector<int> &arr) {
  int maxHeight = arr[0];
  int count = 1;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] >= maxHeight) {
      count++;
      maxHeight = arr[i];
    }
  }
  return count++;
}

int main() {
  vector<int> arr = {6, 2, 8, 4, 11, 13};
  cout << "The total number of buildings that receive sunlight: "
       << visibleBuildings(arr) << "\n";
  return 0;
}
