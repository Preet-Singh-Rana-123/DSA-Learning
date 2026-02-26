#include <iostream>
#include <string>
using namespace std;

// Given the binary representation of an integer as a string s, return the
// number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.
// --------------------------------------------------------------------------
// To solve this we use bit manipulation.
// For e.g. 1101 :-
// 1. 1101 (13) -> 110 (6)
// 2. 110 (6) -> 111 (7)
// 3. 111 (7) -> 1000 (8)
// 4. 1000 (8) -> 100 (4)
// 5. 100 (4) -> 10 (2)
// 6. 10 (2) -> 1
//
// Total 6 steps.

int stepToReduce(string s) {
  int step = 0;
  while (s != "1") {
    if (s.back() == '0') {
      s.pop_back();
    } else {
      int i = s.size() - 1;
      while (i >= 0 && s[i] == '1') {
        s[i] = '0';
        i++;
      }
      if (i < 0) {
        s = s + '1';
      } else {
        s[i] = '1';
      }
    }
    step++;
  }
  return step;
}

int main() {
  string s = "11111000001010101010101010101111000000";
  cout << "Steps taken to reduce binary to one: " << stepToReduce(s) << "\n";
  return 0;
}
