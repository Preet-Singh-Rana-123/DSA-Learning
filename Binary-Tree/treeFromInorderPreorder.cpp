#include <iostream>
using namespace std;

// *********** IMPORTANT ******************
// We can only create tree when we know either know pre-order and in-order or
// post-order and inorder, traversal of tree. Its because in-order traversal
// give us info about, where node is present to their parent parent node as in
// in-order we traverl left then print node and then trave right. Therefore,
// left of node is its left children and right of node is its right children.
// pre-order and post-order are only help in finding node, but in-oder tell us
// about there position w.r.t their paren
//
//
// pre-order:- 1 2 3 7 5
// in-order:- 2 3 1 7 5
//            ---   ---
//      left of 1   right of 1
//
// NOTE:- Also keep in mind that to find tree we need distinct elements. As in
// same data we cannot tell which node we are talking about.

class Node {
public:
  int data;
  Node *left, *right;

  Node(int x) {
    this->data = x;
    this->left = this->right = nullptr;
  }
};

int find(vector<int> &inorder, int key, int inStart, int endStart) {
  for (int i = inStart; i <= endStart; i++) {
    if (inorder[i] == key) {
      return i;
    }
  }
  return -1;
}

// To solve this problem first we have to find position of parent node from
// inorder to know which element will come in left and which in right.
// Now, once we found position in inorder then we split it from that point in
// left part and right part. We will keep doing it recursivly for left and right
// node until we meet our base condition.
//
// inStart is showing start of splited inorder array.
// endStart showing end of splited inorder array.
// index tell us parent node from preorder.
//
// pre: 1-2-3-4-5-6-7
// in:- 4-2-5-1-6-7-3
//            |
//          split

Node *buildTree(vector<int> &inorder, vector<int> &preorder, int index,
                int inStart, int endStart) {
  if (inStart > endStart) {
    return nullptr;
  }

  Node *root = new Node(preorder[index]);
  int pos = find(inorder, preorder[index], inStart, endStart);

  root->left = buildTree(inorder, preorder, index + 1, inStart, pos - 1);
  root->right = buildTree(inorder, preorder, index + (pos - inStart + 1),
                          pos + 1, endStart);

  return root;
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
