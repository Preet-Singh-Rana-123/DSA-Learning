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

// Given the root of a Binary search tree(BST), where exactly two nodes were
// swapped by mistake. Your task is to fix (or correct) the BST by swapping them
// back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes
// that will be wrong. All changes must be reflected in the original Binary
// search tree(BST).
//-------------------------------------------------------------------------
// To solve this problem we follow BST property of inorder traversal which give
// data in ascending order. If we find any irragularities in that order than we
// just have to swap data of irregular nodes.
// Swap Procedure:-
// 2 4 6 12 9 10 7 15 18
// On above traversal we have to swap 12 with 7.

void inorder(Node *root, Node *&first, Node *&second, Node *&prev) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left, first, second, prev);

  // this condition check when data of prev node is more than current node,
  // means we found irregularities.
  if (prev && prev->data > root->data) {
    // store first node we want to swap
    if (first == nullptr) {
      first = prev;
    }
    // store second node we want to swap
    second = root;
  }
  prev = root;

  inorder(root->right, first, second, prev);
}

void fixBST(Node *root) {
  Node *first = nullptr, *second = nullptr, *prev = nullptr;
  inorder(root, first, second, prev);
  if (first && second) {
    swap(first->data, second->data);
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
