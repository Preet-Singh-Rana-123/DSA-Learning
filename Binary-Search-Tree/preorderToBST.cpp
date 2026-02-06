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

// Given an array of integers preorder, which represents the preorder traversal
// of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree
// with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of
// Node.left has a value strictly less than Node.val, and any descendant of
// Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first,
// then traverses Node.left, then traverses Node.right.
// ------------------------------------------------------------------------------
// To solve this problem we follow property of BST that is its left side will be
// less than parent and right side will be greater than parent.
// So, For that for every node we will maintain upper and lower bound and if
// preorder[i] is between then its valid otherwise we will return NULL and then
// create another node and move left and right acc. to preorder traversal and
// check for conditions.

Node *preorderToBST(vector<int> &preorder, int &index, int lower, int upper) {
  if (index > preorder.size() || preorder[index] < lower ||
      preorder[index] > upper) {
    return nullptr;
  }
  Node *root = new Node(preorder[index]);
  index++;
  root->left = preorderToBST(preorder, index, lower, root->data);
  root->right = preorderToBST(preorder, index, root->data, upper);

  return root;
}

Node *insert(Node *root, int data) {
  // case to return when node is null.
  // also in inserting here is where new node created.
  if (root == nullptr) {
    Node *temp = new Node(data);
    return temp;
  }

  if (data < root->data) { // parent's data is more, so insert in left.
    root->left = insert(root->left, data);
  } else { // parent's data is less, so insert in right.
    root->right = insert(root->right, data);
  }

  return root;
}

int main() {
  Node *root = nullptr;
  vector<int> arr = {3, 6, 1, 7, 5, 9, 8, 10};
  for (int i = 0; i < arr.size(); i++) {
    insert(root, arr[i]);
  }
  return 0;
}
