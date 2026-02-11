#include <iostream>
using namespace std;

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

// For heap sort first we have to build max heap and then, first we swap first
// element with last element because first element is greatest se its correct
// position should be in last of arr in sorted form. Then we just perform
// heapify to get next largest no. in index 0. We repeate this step until we get
// fully sorted array.

void heapSort(int arr[], int n) {
  buildHeap(arr, n);

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[i], arr[0]);
    heapify(arr, 0, i);
  }
}

int main() {

  int arr[] = {10, 30, 27, 43, 17, 29, 7, 15, 90, 54, 75, 37};
  heapSort(arr, 12);
  for (int i = 0; i < 12; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
