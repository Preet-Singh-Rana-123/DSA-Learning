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

// Given a Binary Search Tree and a range [low, high]. Find all the numbers in
// the BST that lie in the given range.
// ---------------------------------------------------------------------
// To solve this problem we check if node's data less than range then move left
// and if more than right. Then once we reach range we simply traverse inorder
// and push_back data into ans array.

void bstInRange(Node *root, vector<int> &ans, int low, int high) {
  if (root == nullptr)
    return;

  if (low < root->data && high < root->data) {
    bstInRange(root->left, ans, low, high);
  } else if (low > root->data && high > root->data) {
    bstInRange(root->right, ans, low, high);
  } else {
    bstInRange(root->left, ans, low, high);
    ans.push_back(root->data);
    bstInRange(root->right, ans, low, high);
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
