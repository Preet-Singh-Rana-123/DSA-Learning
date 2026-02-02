#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;

  Node(int x) {
    this->data = x;
    this->left = this->right = nullptr;
  }
};

// You are given the root of a binary tree, and your task is to return its top
// view. The top view of a binary tree is the set of nodes visible when the tree
// is viewed from the top.

// Note:
// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost
// (closest to the root) node is included in the view.
//  ----------------------------------------------------------------------------

// This function is used to find extream points of our tree to find the lenght
// of answer array.
void findExtream(Node *root, int pos, int &l, int &r) {
  if (root == nullptr) {
    return;
  }
  l = min(pos, l);
  r = max(pos, r);

  findExtream(root->left, pos - 1, l, r);
  findExtream(root->right, pos + 1, l, r);
}

// This is the main function that does the work.
// Here when we travel left we only update to ans array when level[pos] >
// current level.
void TView(Node *root, int pos, vector<int> &ans, vector<int> &level, int l) {
  if (root == nullptr) {
    return;
  }

  if (level[pos] > l) {
    ans[pos] = root->data;
    level[pos] = l;
  }

  TView(root->left, pos - 1, ans, level, l + 1);
  TView(root->right, pos + 1, ans, level, l + 1);
}

vector<int> topView(Node *root) {
  int l = 0, r = 0;
  findExtream(root, 0, l, r);
  vector<int> ans(r - l + 1);
  vector<int> level(r - l + 1, INT_MAX);
  TView(root, -1 * l, ans, level, 0);

  return ans;
}

Node *createBinaryTree() {
  int x;
  cin >> x;
  if (x == -1) {
    return nullptr;
  }
  Node *temp = new Node(x);
  temp->left = createBinaryTree();  // handle left part
  temp->right = createBinaryTree(); // handle right node

  return temp;
}

int main() {
  Node *root = createBinaryTree();
  return 0;
}
