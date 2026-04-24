#include <iostream>
#include <string>
using namespace std;

// You are given a string moves of length n consisting only of characters 'L',
// 'R', and '_'. The string represents your movement on a number line starting
// from the origin 0.

// In the ith move, you can choose one of the following directions:

// - move to the left if moves[i] = 'L' or moves[i] = '_'
// - move to the right if moves[i] = 'R' or moves[i] = '_'
// Return the distance from the origin of the furthest point you can get to
// after n moves.
// ----------------------------------------------------------------------------------
// In this problem if we observe that we can get distance by simply counting
// blank space and right and left movement.

int furthestDistanceFromOrigin(string moves) {
  int rCount = 0;
  int lCount = 0;
  int blankCount = 0;
  for (int i = 0; i < moves.size(); i++) {
    if (moves[i] == 'L') {
      lCount++;
    } else if (moves[i] == 'R') {
      rCount++;
    } else {
      blankCount++;
    }
  }
  return rCount > lCount ? rCount + blankCount - lCount
                         : lCount + blankCount - rCount;
}

int main() {
  string moves = "_R__LL_";
  cout << "The distance from the origin of the furthest point you can get to "
          "after n moves: "
       << furthestDistanceFromOrigin(moves) << "\n";
  return 0;
}
