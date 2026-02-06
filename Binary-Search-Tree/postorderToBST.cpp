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

// Given postorder traversal of a Binary Search Tree, you need to construct a
// BST from postorder traversal. The output will be inorder traversal of the
// constructed BST.
// ------------------------------------------------------------------------------
// To solve this problem we will follow same approach as preorder to BST problem
// just in this case our root node will be last element of array and we move in
// node-right-left order this time.

Node *postorderToBST(vector<int> &post, int &index, int lower, int upper) {
  if (index < 0 || post[index] < lower || post[index] > upper) {
    return nullptr;
  }
  Node *root = new Node(post[index]);
  index--;
  root->right = postorderToBST(post, index, root->data, upper);
  root->left = postorderToBST(post, index, lower, root->data);

  return root;
}

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
