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

// Post-Order Traversal is a traversal way for binary tree in which we follow
// Left - Right - Node.
// Post order means Node at last.

void postOrderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }
  postOrderTraversal(root->left);  // Left
  postOrderTraversal(root->right); // Right
  cout << root->data << " ";       // Node
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
