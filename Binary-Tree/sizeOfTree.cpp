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

// For this method we simply traverse binary tree and increase its count

void calculateNode1(Node *root, int &count) {
  if (root == nullptr) {
    return;
  }
  count++;
  calculateNode1(root->left, count);
  calculateNode1(root->left, count);
}

// For this method if there is root node then size will be 1 then we add node
// left to it and node right to it using recursion.

int calculateNode2(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  return 1 + calculateNode2(root->left) + calculateNode2(root->right);
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
  int size = calculateNode2(root);
  cout << "Size of binary tree: " << size << "\n";
  return 0;
}
