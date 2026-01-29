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

// To mirror our tree we just simply traverse tree left and right side and also
// swaping its right and left side.
// For swaping we create temp node and store root->right and then in root->right
// store root->left and in roo->left store temp.

void mirrorTree(Node *root) {
  if (root == nullptr)
    return;

  Node *temp = root->right;
  root->right = root->left;
  root->left = temp;

  mirrorTree(root->left);
  mirrorTree(root->right);
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
  Node *root1 = createBinaryTree();
  mirrorTree(root1);
  return 0;
}
