#include <iostream>
using namespace std;

int findTargetSum(int arr[], int n, int index, int target) {
  if (target == 0) {
    return 1;
  }
  if (target < 0 || index == n) {
    return 0;
  }

  return findTargetSum(arr, n, index + 1, target) +
         findTargetSum(arr, n, index, target - arr[index]);
}

int main() {
  int arr[] = {2, 4, 3};
  int target = 6;
  cout << findTargetSum(arr, 3, 0, target) << "\n";
  return 0;
}
