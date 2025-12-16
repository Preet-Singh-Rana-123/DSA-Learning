#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
  vector<int> temp(end - start + 1);
  int left = start;
  int right = mid + 1;
  int index = 0;

  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {
      temp[index] = arr[left];
      left++;
      index++;
    } else {
      temp[index] = arr[right];
      right++;
      index++;
    }
  }
  while (left <= mid) {
    temp[index] = arr[left];
    index++;
    left++;
  }
  while (right <= end) {
    temp[index] = arr[right];
    index++;
    right++;
  }
  index = 0;
  while (start <= end) {
    arr[start] = temp[index];
    index++;
    start++;
  }
}

void mergeSort(int arr[], int start, int end) {
  if (start == end) {
    return;
  }
  int mid = start + (end - start) / 2;
  mergeSort(arr, mid + 1, end);
  mergeSort(arr, start, mid);
  merge(arr, start, mid, end);
}

int main() {
  int arr1[] = {12, 43, 48, 14, 98, 56, 28, 75, 18};
  mergeSort(arr1, 0, 8);
  for (int i = 0; i < 9; i++) {
    cout << arr1[i] << "\n";
  }
  return 0;
}
