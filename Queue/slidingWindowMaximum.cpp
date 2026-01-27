#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right. You can
// only see the k numbers in the window. Each time the sliding window moves
// right by one position.

// Return the max sliding window.
// ----------------------------------------------------------------------------
// To solve this problem without brute force we have to use deque. And in deque
// we only kept max value of current window as front. To do this we have to keep
// some thins in mind:-
// 1. That we have to pop_back from deque if we found next no. to be greater
// than back of deque because now it will never be max in any other window
// because its front and back both are greater in it cannot be maximum.
// 2. pop_front from deque when its front is out of current window.
// 3. push_back in queue if arr[i] is not greater than arr[d.back] because there
// are chances that it can be maximum in next window.

vector<int> maxSlidingWindow(vector<int> &arr, int k) {
  deque<int> d;
  vector<int> ans;
  for (int i = 0; i < k - 1; i++) {
    if (d.empty()) {
      d.push_back(i);
    } else {
      while (!d.empty() && arr[i] > arr[d.back()]) {
        d.pop_back();
      }
      d.push_back(i);
    }
  }

  for (int i = k - 1; i < arr.size(); i++) {
    while (!d.empty() && arr[i] > arr[d.back()]) {
      d.pop_back();
    }
    d.push_back(i);
    if (d.front() <= i - k) {
      d.pop_front();
    }
    ans.push_back(arr[d.front()]);
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> ans = maxSlidingWindow(nums, 3);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
