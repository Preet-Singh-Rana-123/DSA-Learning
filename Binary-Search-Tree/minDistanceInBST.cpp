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

// Given the root of a Binary Search Tree (BST), return the minimum difference
// between the values of any two different nodes in the tree.
// ---------------------------------------------------------------------
// To solve this problem we us fact that BST's inorder traversal is in assending
// order, because we get min distance between two nodes that are in assending
// order.
// e.g 3,6,8,9,13,15 in this we know that 6-3 give min not 9-3.

void findMin(Node *root, int &prev, int &ans) {
  if (root == nullptr) {
    return;
  }

  findMin(root->left, prev, ans);
  if (prev != INT_MIN) {
    ans = min(ans, root->data - prev);
  }
  prev = root->data;

  findMin(root->right, prev, ans);
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
