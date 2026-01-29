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

// To check weather two tree are identical or not we traverser through both
// trees and compare them.
// For comparision there are 3 main possiblilities:-
// 1. if both r1 and r2 are NULL then both are same and return true.
// 2. if r1 is NULL and r2 not OR r2 is NULL and r1 not, then they are not same
// and return false.
// 3. if r1 and r2 both are not null but there data is different then they are
// not same and return false.

bool isIdentical(Node *r1, Node *r2) {
  if (r1 == nullptr && r2 == nullptr)
    return true;

  if ((!r1 && r2) || (r1 && !r2))
    return false;

  if (r1->data != r2->data)
    return false;

  return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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
  Node *root1 = createBinaryTree();
  Node *root2 = createBinaryTree();

  isIdentical(root2, root1);
  return 0;
}
