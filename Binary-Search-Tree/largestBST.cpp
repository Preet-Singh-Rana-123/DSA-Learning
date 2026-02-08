#include <algorithm>
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

// You're given a binary tree. Your task is to find the size of the largest
// subtree within this binary tree that also satisfies the properties of a
// Binary Search Tree (BST). The size of a subtree is defined as the number of
// nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in
// that subtree, the left child is less than the node, and the right child is
// greater than the node, without any duplicate values in the subtree.
// -------------------------------------------------------------------------
// To solve this problem we have to keep track of size of current node's bst
// size, is current node's subtree is valid bst or not and min and max of for
// node to justify validity of bst. For all this we can make a class BstBox
// which store all these info for current node.

class BstBox {
public:
  bool isBst;
  int min, max, size;

  BstBox() {
    size = 0; // initial size zero because leaf node is valid bst with size 0.
    max = INT_MIN;
    min = INT_MIN;
    isBst = true; // since leaf node is valid bst.
  }
};

BstBox *findLargest(Node *root, int &target) {
  // condition for root node.
  if (root == nullptr) {
    return new BstBox();
  }

  // traversing first left.
  BstBox *leftHead = findLargest(root->left, target);
  // then traverse right.
  BstBox *rightHead = findLargest(root->right, target);

  // now check if leftHead and rightHead are valid bst and also check if root
  // node also make valid bst by comparing max and min limits from both left and
  // right side of node.
  // If on left side max data is less than current node data then it follow BST
  // rule. If on right side min data is more than current node data then it
  // follow BST rule.
  if (leftHead->isBst && rightHead->isBst && root->data > leftHead->max &&
      root->data < rightHead->min) {
    BstBox *head = new BstBox();
    head->size = 1 + leftHead->size + rightHead->size;
    head->max = max(root->data, rightHead->max);
    head->min = min(root->data, leftHead->min);
    target = max(head->size, target); // updating target size.
    return head;
  } else {
    leftHead->isBst = false;
    return leftHead;
  }
}

int largestBST(Node *root) {}

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

int main() {
  Node *root = nullptr;
  vector<int> arr = {3, 6, 1, 7, 5, 9, 8, 10};
  for (int i = 0; i < arr.size(); i++) {
    insert(root, arr[i]);
  }
  return 0;
}
