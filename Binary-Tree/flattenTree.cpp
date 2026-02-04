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

// Given the root of a binary tree, flatten the tree into a "Linked list":

// The "linked list" should use the same Node class where the right child
// pointer points to the next node in the list and the left child pointer is
// always null.
// The "linked list" should be in the same order as a pre-order
// traversal of the binary tree.
// --------------------------------------------------------------------------
//          1
//        /   \
//       2     5
//      / \     \
//     3   4     6
//
//          1
//        /
//       2     5       that's how we flaten our tree
//      /   /  \
//     3 - 4     6
//
// Approach:-
// 1. If root->left does not exists then move to root's right.
// 2. If root's left exists then make node to root's left and move to its right
// until it it gett NULL. Then connect it to root's right and make root's right
// to root' left. Then make root->left NULL and move root to root's left.

void flatteTree(Node *root) {
  while (root) {
    if (!root->left) {
      root = root->right;
    } else {
      Node *curr = root->left;
      while (curr->right) {
        curr = curr->right;
      }
      curr->right = root->right;
      root->right = root->left;
      root->left = nullptr;
      root = root->left;
    }
  }
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
