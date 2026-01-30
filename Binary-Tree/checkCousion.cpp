#include <iostream>
#include <queue>
using namespace std;

class node {
public:
  int data;
  node *left, *right;

  node(int x) {
    this->data = x;
    this->left = this->right = nullptr;
  }
};

// Given a binary tree (having distinct node values)root and two node values.
// Check whether or not the two nodes with values a and b are cousins.
// Note: Two nodes of a binary tree are cousins if they have the same depth with
// different parents.
//------------------------------------------------------------------------------
// To solve this problem we have to solve it in two parts:-
// First:- To check if x and y are on same level.
// Second:- To check if x and y have different parents.
//
// To check same leve we traverl level order and check for each node to find
// match for given numbers and check their levels.
//
// To check if they have same parent or not we traverse left of root node and
// right of root node. Then if for some node if data of left and data of right
// matched then return true. If we find true in either left or right side then
// it will return true.

bool isParent(node *root, int x, int y) {
  if (root == nullptr) {
    return false;
  }
  if (root->left->data == x && root->right->data == y) {
    return true;
  }
  if (root->left->data == y && root->right->data == x) {
    return true;
  }

  return isParent(root->left, x, y) || isParent(root->right, x, y);
}

bool isCousion(node *root, int x, int y) {
  queue<node *> q;
  int l1 = -1; // level of x
  int l2 = -1; // level of y
  int level = 0;
  int n;
  node *temp;
  q.push(root);

  while (!q.empty()) {
    n = q.size();
    while (n--) {
      temp = q.front();
      q.pop();
      if (temp->data == x) {
        l1 = level;
      }
      if (temp->data == y) {
        l2 = level;
      }
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
    level++;

    if (l1 != l2) { // this will return false if level of both are different
      return false;
    }

    if (l1 != -1 && l2 != -1) { // this will break loop if we found level of x
                                // and y. now since we allready check for ther
                                // equivalence so no need to check here.
      break;
    }
  }
  return !isParent(root, x, y);
}

node *createbinarytree() {
  int x;
  cin >> x;
  if (x == -1) {
    return nullptr;
  }
  node *temp = new node(x);
  temp->left = createbinarytree();  // handle left part
  temp->right = createbinarytree(); // handle right node

  return temp;
}

int main() {
  node *root = createbinarytree();
  return 0;
}
