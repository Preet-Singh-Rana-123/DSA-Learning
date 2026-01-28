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

// Pre-Order Traversal is a traversal way for binary tree in which we follow
// Node - Left - Right.
// Pre order means Node first then left right.

void preOrderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->data << " ";      // Node
  preOrderTraversal(root->left);  // Left
  preOrderTraversal(root->right); // Right
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
