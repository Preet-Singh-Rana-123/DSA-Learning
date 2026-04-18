#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxOnes(vector<int> &arr) {
  int n = arr.size();
  int totalOnes = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1)
      totalOnes++;
  }

  int currGain = 0;
  int maxGain = 0;

  for (int i = 0; i < n; i++) {
    int val = arr[i] == 0 ? 1 : -1;

    currGain = max(val, currGain + val);
    maxGain = max(maxGain, currGain);
  }

  return maxGain + totalOnes;
}

int main() {
  vector<int> arr = {1, 0, 0, 1, 0, 0, 1};
  cout << "The maximum number of 1's you can get in the array after doing at "
          "most 1 flip operation: "
       << maxOnes(arr) << "\n";
  return 0;
}
