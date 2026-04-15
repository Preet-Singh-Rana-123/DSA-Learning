#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// You are given a 0-indexed circular string array words and a string target. A
// circular array means that the array's end connects to the array's beginning.

// Formally, the next element of words[i] is words[(i + 1) % n] and the previous
// element of words[i] is words[(i - 1 + n) % n], where n is the length of
// words.
// Starting from startIndex, you can move to either the next word or the
// previous word with 1 step at a time.

// Return the shortest distance needed to reach the string target. If the string
// target does not exist in words, return -1.

int closestTarget(vector<string> &words, string target, int startIndex) {
  int n = words.size();

  if (words[startIndex] == target)
    return 0;

  int minDist = INT_MAX;

  // Case of moving in forward direction
  int steps = 1;
  int i = (startIndex + 1) % n;
  while (i != startIndex) {
    if (words[i] == target) {
      minDist = min(minDist, steps);
    }
    steps++;
    i = (i + 1) % n;
  }

  // Case of moving in backward direction
  steps = 1;
  i = (startIndex - 1 + n) % n;
  while (i != startIndex) {
    if (words[i] == target) {
      minDist = min(minDist, steps);
    }
    steps++;
    i = (i - 1 + n) % n;
  }

  return minDist == INT_MAX ? -1 : minDist;
}

int main() {
  vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
  string target = "hello";
  cout << "Shortest distance in circular array to find " << target
       << " is: " << closestTarget(words, target, 1) << "\n";
  return 0;
}
