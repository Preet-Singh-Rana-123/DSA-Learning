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

// For node to become a leaf it should have no children. Therefore we traverse
// tree and return 1 where root->left and root->right are nullptr. Then we just
// add them all.
int countLeaves(Node *root) {
  if (root == nullptr)
    return 0;

  if (root->left == nullptr && root->right == nullptr)
    return 1;

  return countLeaves(root->left) + countLeaves(root->right);
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
  int leaves = countLeaves(root);
  cout << "Size of binary tree: " << leaves << "\n";
  return 0;
}
