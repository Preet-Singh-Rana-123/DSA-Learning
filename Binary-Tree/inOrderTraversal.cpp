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

// In-Order Traversal is a traversal way for binary tree in which we follow
// Left - Node - Right.
// In order means Node in middle and left right at their places

void inOrderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  inOrderTraversal(root->left);  // Left
  cout << root->data << " ";     // Node
  inOrderTraversal(root->right); // Right
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
