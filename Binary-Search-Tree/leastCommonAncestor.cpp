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

// Given the root of a Binary Search Tree (with all values unique) and two nodes
// n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find
// the Lowest Common Ancestor (LCA) of the given two nodes in the BST.
// ------------------------------------------------------------------
// To solve this problem we simply check if n1 and n2 both are greater than
// node's data that means they are in right direction. Similarly if n1 and n2
// less than node's data than they are in left.
// At last once they diverge means now we just need to return root because that
// node will be now their least common Ancestor.

Node *leastCommonAncenstor(Node *root, int n1, int n2) {
  if (root == nullptr) {
    return nullptr;
  }

  if (n1 < root->data && n2 < root->data) {
    return leastCommonAncenstor(root->left, n1, n2);
  } else if (n1 > root->data && n2 > root->data) {
    return leastCommonAncenstor(root->right, n1, n2);
  } else {
    return root;
  }
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
