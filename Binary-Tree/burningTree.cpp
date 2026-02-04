#include <cstdlib>
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

// Given the root of a binary tree and a target node, determine the minimum time
// required to burn the entire tree if the target node is set on fire. In one
// second, the fire spreads from a node to its left child, right child, and
// parent.

// Note: The tree contains unique values.
// ------------------------------------------------------------------------
// To solve this problem we find burn time according to different conditions.

int height(Node *root) {
  if (root == nullptr)
    return 0;

  return 1 + max(height(root->left), height(root->right));
}

void findBurnNode(Node *root, int target, Node *&burnNode) {
  if (root == nullptr)
    return;

  if (root->data == target) {
    burnNode = root;
    return;
  }

  findBurnNode(root->left, target, burnNode);
  findBurnNode(root->right, target, burnNode);
}

// This is main function which is finding burn time.
int burn(Node *root, int target, int &timer) {
  // base case to return when root is NULL.
  if (root == nullptr)
    return 0;

  // case wher we find target in tree and now it will take 1 sec to burn parent
  // node. -ve sign to show it giving burning time.
  if (root->data == target) {
    return -1;
  }

  // traversing left and right of tree.
  int left = burn(root->left, target, timer);
  int right = burn(root->right, target, timer);

  // cases when we have to return burning case as burning case reperesent by
  // negative no., so there will be two cases when right is -vw and when left is
  // -ve. Here we return buring time in negative because this is case of burn,
  // therefore here is -1. we also updating timer by max(timer,left+right);
  if (left < 0) {
    timer = max(timer, abs(left) + right);
    return left - 1;
  }
  if (right < 0) {
    timer = max(timer, abs(right) + left);
    return right - 1;
  }

  // normal case where no burn find and to return max height in +ve no.
  return 1 + max(left, right);
}

int burnTime(Node *root, int target) {
  int timer = 0;
  burn(root, target, timer);

  Node *burnNode;
  findBurnNode(root, target, burnNode);

  int high = height(burnNode) - 1;

  return max(high, timer);
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
