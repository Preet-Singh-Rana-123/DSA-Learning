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

// This method uses recursion to create binary tree.
// In this we follow some step:-
// 1. Take input 'x' from user.
// 2. If x==-1 then its our base condition and return a null pointer.
// 3. We create temp node which will store data on input 'x'.
// 4. Then we go to left and fill out all left node.
// 5. After filling left nodes then we fill right nodes.
// 6. At last when recursive tree comes to first node then we return that node.

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
