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

// You are given a Binary Search Tree (BST) containing unique positive integers
// greater than 0.

// Your task is to determine whether the BST contains a dead end.

// Note: A dead end is a leaf node in the BST such that no new node can be
// inserted in the BST at or below this node while maintaining the BST property
// and the constraint that all node values must be > 0.
// ------------------------------------------------------------------------------
// To solve this problem we maintain a range for every node and if range's
// differnce for that == 2,this means we cannot add anything on that node
// because let say that range is of 20 and 22 this means node's data will be 21
// and now be cannnot add anything new on left and right of 21 because they are
// already present on ancestor node.

void findDeadEnd(Node *root, bool &isDeadEnd, int low, int high) {
  if (root == nullptr)
    return;

  if (high - low == 2)
    isDeadEnd = true;

  findDeadEnd(root->left, isDeadEnd, low, root->data);
  findDeadEnd(root->right, isDeadEnd, root->data, high);
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
