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

// Given a Binary Search Tree. Your task is to complete the function which will
// return the kth largest element without doing any modification in the Binary
// Search Tree.
// -----------------------------------------------------------------
// To solve this problem we will once again do inorder traversal but this time
// we go right-node-left to traverse in descending order. By this we can easily
// get kth largest no.

void findKLargest(Node *root, int &k, int &ans) {
  if (root == nullptr) {
    return;
  }
  findKLargest(root->right, k, ans);
  k--;
  if (k == 0) {
    ans = root->data;
    return;
  }
  if (k <= 0) {
    return;
  }
  findKLargest(root->left, k, ans);
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
