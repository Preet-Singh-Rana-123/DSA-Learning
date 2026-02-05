#include <iostream>
#include <vector>
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

// Binary search tree is a special kind of Binary tree in which the parent
// node's left side is less and right side is greater than parent node's data.
// It is usefull in searching of element effectively.
//
// Keep in mind that inorder traversal of bst is always in ascening order.

// insertion time-comlexity:- O(h), his height of tree.
Node *insert(Node *root, int data) {
  // case to return when node is null.
  // also in inserting here is where new node created.
  if (root == nullptr) {
    Node *temp = new Node(data);
    return temp;
  }

  if (data < root->data) { // parent's data is more, so insert in left.
    root->left = insert(root->left, data);
  } else { // parent's data is less, so insert in right.
    root->right = insert(root->right, data);
  }

  return root;
}

// searching in Binary search tree is just like binary search. where we only
// deal with part where target is less or more than root data.
// Time Comlexity: O(log n)
bool search(Node *root, int target) {
  if (root == nullptr) {
    return false;
  }

  if (root->data == target) {
    return true;
  }
  if (root->data > target) {
    search(root->left, target);
  } else {
    search(root->right, target);
  }
  return false;
}

// Time Comlexity: O(log n)
Node *deleteNode(Node *root, int target) {
  // base condition
  if (root == nullptr) {
    return nullptr;
  }

  if (root->data > target) {
    root->left = deleteNode(root->left, target);
    return root;
  } else if (root->data < target) {
    root->right = deleteNode(root->right, target);
    return root;
  } else {
    // deleting leaf node
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    // one child exists
    else if (root->left == nullptr) { // if only root's right exists
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) { // if only root's left exists
      Node *temp = root->left;
      delete root;
      return temp;
    }
    // both child exists
    else {
      // now we have find largest elemet from left and replace it with deleting
      // node.
      Node *child = root->left;
      Node *parent = root;

      // now we move child to extreme right to find largest element from left of
      // root.
      while (child->right) {
        parent = child;
        child = child->right;
      }
      // if parent node is not root
      if (root != parent) {
        parent->right = child->left;
        child->left = root->left;
        child->right = root->right;
        delete root;
        return child;
      } else {
        child->right = root->right;
        delete root;
        return child;
      }
    }
  }
}

int main() {
  Node *root = nullptr;
  vector<int> arr = {3, 6, 1, 7, 5, 9, 8, 10};
  for (int i = 0; i < arr.size(); i++) {
    insert(root, arr[i]);
  }
  return 0;
}
