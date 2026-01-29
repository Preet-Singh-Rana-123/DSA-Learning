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

// To find sum of binary tree we traverse tree using recursion and add data of
// every node.
int sumBT(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  return root->data + sumBT(root->left) + sumBT(root->right);
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
  int sum = sumBT(root);
  cout << "Size of binary tree: " << sum << "\n";
  return 0;
}
