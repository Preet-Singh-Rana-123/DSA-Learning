#include <algorithm>
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

// Given a root of a Binary Tree, return its boundary traversal in the following
// order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring
// the left child over the right and excluding leaves.

// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the
// tree.

// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node,
// preferring the right child over the left, excluding leaves, and added in
// reverse order.

// Note: The root is included once, leaves are added separately to avoid
// repetition, and the right boundary follows traversal preference not the path
// from the rightmost leaf.
// --------------------------------------------------------------------------------
// To solve this problem first we push root node's data in ans vector.
// Then we add all left of the tree if exists else add right. Also here we does
// not add leaf nodes.
// Then we add leaf nodes of the tree.
// After that we simply add right of root node if exists else left, in reverse
// direction. Here, also we does not add leaf node.

void addLeft(Node *root, vector<int> &ans) {
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr)
    return;

  ans.push_back(root->data);
  if (root->left) {
    addLeft(root->left, ans);
  } else {
    addLeft(root->right, ans);
  }
}

void addLeaf(Node *root, vector<int> &ans) {
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr) {
    ans.push_back(root->data);
    return;
  }

  addLeaf(root->left, ans);
  addLeaf(root->right, ans);
}

void addRightReverse(Node *root, vector<int> &ans) {
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr)
    return;

  if (root->right) {
    addRightReverse(root->right, ans);
  } else {
    addRightReverse(root->left, ans);
  }
  ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root) {
  vector<int> ans;

  ans.push_back(root->data);

  addLeft(root->left, ans);
  addLeaf(root->left, ans);
  addLeaf(root->right, ans);
  addRightReverse(root->right, ans);

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
