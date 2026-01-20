#include <iostream>
#include <vector>
using namespace std;

// Given an array of negative and non-negative integers. You have to make the
// array beautiful. An array is beautiful if two adjacent integers, arr[i] and
// arr[i+1] are either negative or non-negative. And you can do the following
// operation any number of times until the array becomes beautiful.

// If two adjacent integers are different i.e. one of them is negative and other
// is non-negative, remove them. Return the beautiful array after performing the
// above operation.
//
//-------------------------------------------------------------------------------
//
// To solve this we push arr[0] to the stack first then we check if(arr[i]>0) if
// yes then if stack's top is also > 0 then push arr[i] into stack and if
// stack's top is < 0 then pop from stack.
// We can also do same for arr[i]<0 case.
stack<int> makeArrayBeautiful(vector<int> arr) {
  stack<int> s;
  for (int i = 0; i < arr.size(); i++) {
    if (s.empty()) {
      s.push(arr[i]);
    } else if (arr[i] >= 0) {
      if (s.top() >= 0) {
        s.push(arr[i]);
      } else {
        s.pop();
      }
    } else {
      if (s.top() < 0) {
        s.push(arr[i]);
      } else {
        s.pop();
      }
    }
  }
  return s;
}

int main() {
  vector<int> arr = {4, 2, -2, 1};
  stack<int> ans = makeArrayBeautiful(arr);
  return 0;
}
