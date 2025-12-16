#include <iostream>
using namespace std;

bool findTargetSum(int arr[], int n, int index, int target) {
  if (target == 0) {
    return 1;
  }
  if (target < 0 || index == n) {
    return 0;
  }

  return findTargetSum(arr, n, index + 1, target) ||
         findTargetSum(arr, n, index + 1, target - arr[index]);
}

int main() {
  int arr[] = {12, 53, 2, 1, 5, 2};
  int target = 7;
  cout << findTargetSum(arr, 6, 0, target) << "\n";
  return 0;
}
