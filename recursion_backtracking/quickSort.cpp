#include <iostream>
#include <utility>
using namespace std;

int partition(int arr[], int start, int end) {
  int pos = start;
  for (int i = start; i <= end; i++) {
    if (arr[end] >= arr[i]) {
      swap(arr[i], arr[pos]);
      pos++;
    }
  }
  return pos - 1;
}

void quickSort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = partition(arr, start, end);
  quickSort(arr, start, pivot - 1);
  quickSort(arr, pivot + 1, end);
}

int main() {
  int arr[] = {13, 56, 12, 54, 28, 95, 56, 97, 8, 45, 27};
  quickSort(arr, 0, 10);
  for (int i = 0; i < 11; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
