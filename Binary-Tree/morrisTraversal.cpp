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

// Morris traversal allow us to travers tree in O(1) time complexity, without
// recursion.

// In-Order traversal pseudocode:-
// 1. If left does not exist:- push data and move to right.
// 2. If left exists:-
//    i) If left subtree not traverse:- create link and move to left.
//    ii) If left subtree traverse remove link, push data and move to right.

vector<int> inorderTraversal(Node *root) {
  vector<int> ans;
  while (root) {
    if (!root->left) {
      ans.push_back(root->data);
      root = root->right;
    } else {
      Node *curr = root->left;
      while (curr->right && curr->right != root) {
        curr = curr->right;
      }
      if (curr->right == nullptr) {
        curr->right = root;
        root = root->left;
      } else {
        curr->right = nullptr;
        ans.push_back(root->data);
        root = root->right;
      }
    }
  }
  return ans;
}

// Pre-Order traversal pseudocode:-
// 1. If left does not exist:- push data and move to right.
// 2. If left exists:-
//    i) If left subtree not traverse:- create link, push data and move to left.
//    ii) If left subtree traverse remove link and move to right.

vector<int> preOrderTraversal(Node *root) {
  vector<int> ans;
  while (root) {
    if (!root->left) {
      ans.push_back(root->data);
      root = root->right;
    } else {
      Node *curr = root->left;
      while (curr->right && curr->right != root) {
        curr = curr->right;
      }
      if (curr->right == nullptr) {
        curr->right = root;
        ans.push_back(root->data);
        root = root->left;
      } else {
        curr->right = nullptr;
        root = root->right;
      }
    }
  }
  return ans;
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
