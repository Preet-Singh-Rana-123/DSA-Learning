#include <iostream>

using namespace std;

class Node {
public:
  int data, height;
  Node *left, *right;

  Node(int value) {
    data = value;
    height = 1;
    left = right = nullptr;
  }
};

// An AVL tree defined as a self-balancing Binary Search Tree (BST) where the
// difference between heights of left and right subtrees for any node cannot be
// more than one.
// Rotations: rotations are designed to restore balance in O(1)
// time while ensuring the overall time complexity remains O(log n). AVL Trees
// use four cases to rebalance themselves after insertions and deletions:
// Left-Left (LL), Right-Right (RR), Left-Right (LR) and Right-Left (RL)
// 1. Left-Left Case:
// Occurs when a node is inserted into the left subtree of the left child,
// causing the balance factor to become more than +1.
// Fix: Perform a single right rotation.
// 2. Right-Right Case:
// Occurs when a node is inserted into the right subtree of the right child,
// making the balance factor less than -1.
// Fix: Perform a single left rotation.
// 3. Left-Right Case:
// Occurs when a node is inserted into the right subtree of the left child,
// which disturbs the balance factor of an ancestor node, making it left-heavy.
// Fix: Perform a left rotation on the left child, followed by a right rotation
// on the node.
// 4. Right-Left Case:
// Occurs when a node is inserted into the left subtree of the right child,
// which disturbs the balance factor of an ancestor node, making it right-heavy.
// Fix: Perform a right rotation on the right child, followed by a left rotation
// on the node.

int getHeight(Node *root) {
  if (root == nullptr) {
    return 0;
  }

  return root->height;
}

Node *rightRotation(Node *root) {
  Node *child = root->left;
  Node *childRight = child->right;

  child->right = root;
  root->left = childRight;

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

Node *leftRotation(Node *root) {
  Node *child = root->right;
  Node *childLeft = child->left;

  child->left = root;
  root->right = childLeft;

  // update height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  child->height = 1 + max(getHeight(child->left), getHeight(child->right));

  return child;
}

int getBalance(Node *root) {
  return getHeight(root->left) - getHeight(root->right);
}

Node *insert(Node *root, int key) {
  if (root == nullptr) {
    return new Node(key);
  }

  if (key < root->data) { // left side
    root->left = insert(root->left, key);
  } else if (key > root->data) { // right side
    root->right = insert(root->right, key);
  } else { // no duplicate value
    return root;
  }

  // updating height
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));

  // Balancing check
  int balance = getBalance(root);

  // left-left case
  if (balance > 1 && key < root->left->data) {
    return rightRotation(root);
  }
  // right-right case
  else if (balance < -1 && key > root->right->data) {
    return leftRotation(root);
  }
  // left-right case
  else if (balance > 1 && key > root->right->data) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
  }
  // right-left case
  else if (balance < -1 && key < root->left->data) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
  }
  // no unbalancing
  else {
    return root;
  }
}

int main() {

  Node *root = nullptr;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 50);
  root = insert(root, 70);
  root = insert(root, 5);
  root = insert(root, 100);
  root = insert(root, 95);

  return 0;
}
