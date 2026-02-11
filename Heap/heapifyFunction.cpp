#include <iostream>

using namespace std;

// By using heapify function to build heap we used step-down approach which
// means we are comparing parent node with its child. Using this approach we can
// build Heap in O(n) time.

void heapify(int arr[], int index, int n) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  // Condition to check if left child is greater than parent.
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  // Condition to check if right child is greater than parent.
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  // Condition to check if we found largest element in child node than parent
  // node then we have to swap them.
  if (largest != index) {
    swap(arr[index], arr[largest]);
    heapify(arr, largest, n);
  }
}

void buildHeap(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, i, n);
  }
}

int main() {

  int arr[] = {10, 30, 27, 43, 17, 29, 7, 15, 90, 54, 75, 37};
  buildHeap(arr, 12);

  return 0;
}
