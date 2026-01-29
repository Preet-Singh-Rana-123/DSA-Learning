#include <cstdlib>
#include <iostream>
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

// Given the root of a binary tree, determine if it is height-balanced or not.

// Note: A binary tree is considered height-balanced if the absolute difference
// in heights of the left and right subtrees is at most 1 for every node in the
// tree.
//
// ----------------------------------------------------------------------------

// To check wether tree is balanced or not, we will make a valid flag and find
// height for left and height for right and compare them to check weather tree
// is balanced and if not then we just simply make valid flag false.

int height(Node *root, bool &valid) {
  if (root == nullptr) {
    return 0;
  }

  int left = height(root->left, valid);
  int right = height(root->right, valid);

  if (abs(left - right) > 1) {
    valid = false;
  }

  return 1 + left + right;
}

bool isBalanced(Node *root) {
  bool valid = true;
  height(root, valid);
  return valid;
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
