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

// Deletion of node of avl tree is similar to binary search tree. Just we also
// have to keep in mind of rotation part for self balancing.

Node *deleteNode(Node *root, int key) {
  if (root == nullptr) {
    return nullptr;
  }

  if (key < root->data) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->data) {
    root->right = deleteNode(root->right, key);
  } else {
    // leaf Node
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    // only left child exists
    else if (root->left && root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // only right child exists
    else if (root->right && root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    }
    // both child exists
    else {
      Node *curr = root->right;
      while (curr) {
        curr = curr->left;
      }
      curr->data = root->data;
      root->right = deleteNode(root->right, curr->data);
    }
  }

  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int balance = getBalance(root);

  // left side unbalance
  if (balance > 1) {
    // left-left case
    if (getBalance(root->left) >= 0) {
      return rightRotation(root);
    }
    // left right case
    else {
      root->left = leftRotation(root->left);
      return rightRotation(root);
    }
  }
  // right side unbalance
  else if (balance < -1) {
    // right right case
    if (getBalance(root->right) <= 0) {
      return leftRotation(root);
    }
    // right left case
    else {
      root->right = rightRotation(root->right);
      return leftRotation(root);
    }
  } else {
    return root;
  }
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
