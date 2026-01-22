#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// You are given an array arr[] of integers, the task is to find the next
// greater element for each element of the array in order of their appearance in
// the array. Next greater element of an element in the array is the nearest
// element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater
// element for current element is -1.
// ---------------------------------------------------------------------------
// To solve this question in O(n) time complexity we will use stack to store the
// index of numbers whoes greater we havent seen, once we saw greater of that
// number then we just update it in our ans vector.
//
// For checking have we seen greater we first start from 0 index and as we
// haven't seen its greater we simply push it into stack. After that we move to
// next index and if stack's top is greater than number at index then we have
// find greater of stack's top index number so now we update in answer vector.
// If number at array index is not greater than number at stack's top index then
// we simply push that numbers index into stack as now we also have to find its
// next greater for next iteration.

vector<int> nextGreaterNumber(vector<int> &arr) {
  stack<int> st;
  vector<int> ans(arr.size(), -1);
  for (int i = 0; i < arr.size(); i++) {
    while (!st.empty() && arr[i] > arr[st.top()]) {
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

int main() {
  vector<int> arr = {6, 8, 0, 1, 3};
  vector<int> ans = nextGreaterNumber(arr);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
