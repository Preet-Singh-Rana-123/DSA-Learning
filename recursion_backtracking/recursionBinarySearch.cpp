#include "iostream"
using namespace std;

int binary_search(int arr[], int key, int start, int end) {
  int mid = start + (end - start) / 2;
  if (arr[mid] == key) {
    return mid;
  } else if (arr[mid] > key) {
    return binary_search(arr, key, start, mid - 1);
  } else if (arr[mid] < key) {
    return binary_search(arr, key, mid + 1, end);
  } else {
    return -1;
  }
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int key = 9;
  int foundIndex = binary_search(arr1, key, 0, 9);
  cout << foundIndex;

  return 0;
}
