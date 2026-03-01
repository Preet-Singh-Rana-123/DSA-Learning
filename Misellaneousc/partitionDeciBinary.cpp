#include <iostream>
#include <string>
using namespace std;

// A decimal number is called deci-binary if each of its digits is either 0 or 1
// without any leading zeros. For example, 101 and 1100 are deci-binary, while
// 112 and 3001 are not.

// Given a string n that represents a positive decimal integer, return the
// minimum number of positive deci-binary numbers needed so that they sum up to
// n.
// ---------------------------------------------------------------------------
// To solve this problem if we observer that minimum deci-binary partition
// required will be the largest digit in the give number, because to make that
// no. we have add 1 atmost largest digit times.

int minPartition(string s) {
  int maxNum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (maxNum < s[i] - '0') {
      maxNum = s[i] - '0';
    }
  }
  return maxNum;
}

int main() {
  string s = "275372815374";
  cout << "the minimum number of positive deci-binary numbers needed so that "
          "they sum up to 275372815374: "
       << minPartition(s) << "\n";
  return 0;
}
