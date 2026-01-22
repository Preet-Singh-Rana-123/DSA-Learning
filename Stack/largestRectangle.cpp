#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Given an array of integers heights representing the histogram's bar height
// where the width of each bar is 1, return the area of the largest rectangle in
// the histogram.
// -----------------------------------------------------------------------------
// To solve this problem we need to figure out rectangle that can be formed from
// given heights index.
// To get posible rectangle we can see that for index the smallest from the left
// and smallest from right will be the end part for rectangle. Because upto
// smallest from left and right that rectangle will go.
// Now we just find smallest from left and smallest from right for every index.
// By that we get width for rectangle and height for rectangle will be the
// height.
// After we get area for every index's rectangle we can easily find
// maximum out of them.

vector<int> nextSmallestRight(vector<int> &arr) {
  stack<int> st;
  vector<int> ans(arr.size(), arr.size());
  for (int i = 0; i < arr.size(); i++) {
    while (!st.empty() && arr[i] < arr[st.top()]) {
      ans[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextSmallestLeft(vector<int> &arr) {
  stack<int> st;
  vector<int> ans(arr.size(), -1);
  for (int i = arr.size() - 1; i >= 0; i--) {
    while (!st.empty() && arr[i] < arr[st.top()]) {
      ans[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  return ans;
}

int largestRectangleArea(vector<int> &heights) {
  vector<int> nsr = nextSmallestRight(heights);
  vector<int> nsl = nextSmallestLeft(heights);
  int maxArea = 0;
  int area = 0;
  for (int i = 0; i < heights.size(); i++) {
    area = heights[i] * (nsr[i] - nsl[i] - 1);
    maxArea = max(maxArea, area);
  }
  return maxArea;
}

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << "Largest histogram area: " << largestRectangleArea(heights) << "\n";
  return 0;
}
