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

// Given the root of a binary tree. Check whether it is a BST or not.

// A BST is defined as follows:

// The left subtree of a node contains only nodes with data less than the node's
// data. The right subtree of a node contains only nodes with data greater than
// the node's data. Both the left and right subtrees must also be binary search
// trees. Note: We are considering that BSTs can not contain duplicate Nodes.
// ---------------------------------------------------------------------
// To check if BST is valid we will use fact that inorder traversal of BST is in
// ascending order. So, if we traverse inorder way in first left-node-right and
// keep check value of prev node and if its greater than current node then that
// tree is not valid BST.

bool isBST(Node *root, int &prev) {
  // Base condition return 1 because single node will always be a valid BST.
  if (root == nullptr) {
    return 1;
  }

  // here we traverse to left of tree
  int l = isBST(root->left, prev);
  // if left of tree return false that means its not valid tree
  if (l == 0) {
    return 0;
  }

  // condition check for if node's data == prev
  if (root->data <= prev) {
    return 0;
  }

  // updating prev with previous node.
  prev = root->data;

  // last traversing to right
  return isBST(root->right, prev);
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
