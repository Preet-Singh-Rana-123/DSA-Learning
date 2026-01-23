#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// A celebrity is a person who is known to all but does not know anyone at a
// party. A party is being organized by some people. A square matrix mat[][] of
// size n*n is used to represent people at the party such that if an element of
// row i and column j is set to 1 it means ith person knows jth person. You need
// to return the index of the celebrity in the party, if the celebrity does not
// exist, return -1.
// -----------------------------------------------------------------------------
// To solve this problem in O(n) time complexity we will use stack.
// First celibrity is a person who doesn't know anyone but everyone knows him.
// For that first we keep ever person in stack and then we pop top two persons
// and then compare them if p1 knows p2 then p1 is not celebrity because he/she
// know other person but if p1 does not know other p2 then there is chances that
// p1 can be a celeibrity therefore we push p1 back to stack and then compare it
// further with other person in stack(vice versa for p2 and p1 also follow
// same).

int findCelebrity(vector<vector<int>> &mat) {
  stack<int> st;
  int n = mat.size();
  for (int i = n - 1; i >= 0; i--) {
    st.push(i);
  }

  while (st.size() > 1) {
    int p1 = st.top();
    st.pop();
    int p2 = st.top();
    st.pop();
    if (mat[p1][p2] && !mat[p2][p1]) {
      st.push(p2);
    } else if (mat[p2][p1] && !mat[p1][p2]) {
      st.push(p1);
    }
  }

  if (st.empty())
    return -1;

  int p = st.top();
  int row = 0;
  int col = 0;
  for (int i = 0; i < n; i++) {
    row += mat[p][i];
    col += mat[i][p];
  }

  return col == n && row == 1 ? p : -1;
}

int main() {
  vector<vector<int>> mat = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
  cout << "Celebrity is Person: " << findCelebrity(mat) << "\n";
  return 0;
}
