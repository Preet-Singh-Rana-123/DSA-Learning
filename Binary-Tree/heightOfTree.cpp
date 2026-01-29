
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

// Height of tree is the number of edges on the longest path from the root node
// to the farthest leaf node.
// To find height of tree we just add 1 with max(root->left length, root->right
// length).

int height(Node *root) {
  if (root == nullptr) {
    return -1; // -1 because we are callculating based on nodes but height
               // calculate based on edges and since edges = heigth -1
  }

  return 1 + max(height(root->left), height(root->right));
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
  cout << "Size of binary tree: " << height(root) << "\n";
  return 0;
}
