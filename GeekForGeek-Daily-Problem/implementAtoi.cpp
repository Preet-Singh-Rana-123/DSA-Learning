#include <cctype>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

// Given a string s, convert it into a 32-bit signed integer (similar to the
// atoi() function) without using any built-in conversion functions.
// The conversion follows these rules:

// Ignore Leading Whitespaces: Skip all leading whitespace characters.
// Check Sign: If the next character is either '+' or '-', take it as the sign
// of the number. If no sign is present, assume the number is positive. Read
// Digits: Read the digits and ignore any leading zeros. Stop reading when a
// non-digit character is encountered or the end of the string is reached. If no
// digits are found, return 0. Handle Overflow: If the number exceeds the range
// of a 32-bit signed integer: Return 2³¹ − 1 (i.e., 2147483647) if it is
// greater than the maximum value. Return −2³¹ (i.e., -2147483648) if it is
// smaller than the minimum value. Return the final integer value.
//--------------------------------------------------------------------------------

int myAtoi(string &s) {
  int i = 0;
  int n = s.size();
  int sign = 1;

  // trim Whitespaces
  while (i < n && s[i] == ' ') {
    i++;
  }

  // finding about sign
  if (i < n && s[i] == '+' || s[i] == '-') {
    if (s[i] == '-')
      sign = -1;
    i++;
  }

  // calculating integer
  int ans = 0;
  while (i < n && isdigit(s[i])) {
    int n = s[i] - '0';
    // checking overflow condition
    if (ans * 10 + n > INT_MAX)
      return sign == -1 ? INT_MIN : INT_MAX;
    ans = ans * 10 + n;
    i++;
  }
  return ans * sign;
}

int main() {
  string s = "-12345";
  cout << "Number after ATOI: " << myAtoi(s) << "\n";
  return 0;
}
