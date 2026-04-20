#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Given an array arr, replace every element in that array with the greatest
// element among the elements to its right, and replace the last element with
// -1.

// After doing so, return the array.
// --------------------------------------------------------------------
// To solve this we will check from end keep updating the left elements as we
// traverse with maxNum in right.

vector<int> replaceElements(vector<int> &arr) {
  int n = arr.size();
  int maxNum = -1;
  for (int i = n - 1; i >= 0; i--) {
    // storing current arr[i] to compare it with maxNum from right as we can
    // encounter max num while miving in left direction
    int current = arr[i];
    arr[i] = maxNum;
    maxNum = max(maxNum, current);
  }
  return arr;
}

int main() {
  vector<int> arr = {17, 18, 5, 4, 6, 1};
  replaceElements(arr);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return 0;
}
