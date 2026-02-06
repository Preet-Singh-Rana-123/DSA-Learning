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

// Given a sorted array arr[]. Convert it into a Height Balanced Binary Search
// Tree (BST) and return the root of the BST.

// Height-balanced BST means a binary tree in which the depth of the left
// subtree and the right subtree of every node never differ by more than 1.
// ---------------------------------------------------------------------
// To create BST from a sorted array, we first find mid of that array aand made
// it root node of BST because on mid of sorted array left side will be small
// and right side will be big than root node which will follow BST property. To
// do that we follow steps:-
// 1. find mid of array.
// 2. create node with arr[mid] ans value.
// 3. node's left will be from start of array to mid-1.
// 4. node's right will be from mid+1 to end.
// 5. base condition will be when start > end.

Node *createBST(vector<int> &arr, int start, int end) {
  if (start > end) {
    return nullptr;
  }

  int mid = start + (end - start) / 2;
  Node *root = new Node(arr[mid]);
  root->left = createBST(arr, start, mid - 1);
  root->right = createBST(arr, mid + 1, end);

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
