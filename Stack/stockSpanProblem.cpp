#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// The stock span problem is a financial problem where we have a series of daily
// price quotes for a stock and we need to calculate the span of stock price for
// all days. You are given an array arr[] representing daily stock prices, the
// stock span for the i-th day is the number of consecutive days up to day i
// (including day i itself) for which the price of the stock is less than or
// equal to the price on day i. Return the span of stock prices for each day in
// the given sequence.
// ------------------------------------------------------------------------------
// To solve this problem in O(n) time complexity we can use stack concept with
// greater from left.
// For that we first first greater from left for index i in arr and then to find
// stock less than stack's top we simply subtract stack's top from index at
// which loop present.

vector<int> calculateSpan(vector<int> &arr) {
  stack<int> st;
  vector<int> ans(arr.size(), 1);
  for (int i = arr.size() - 1; i >= 0; i--) {
    while (!st.empty() && arr[i] > arr[st.top()]) {
      ans[st.top()] = st.top() - i;
      st.pop();
    }
    st.push(i);
  }
  while (!st.empty()) {
    ans[st.top()] = st.top() + 1;
    st.pop();
  }
  return ans;
}

int main() {
  vector<int> stocks = {10, 4, 5, 90, 120, 80};
  vector<int> ans = calculateSpan(stocks);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
