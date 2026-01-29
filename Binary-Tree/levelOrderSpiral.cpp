#include <iostream>
#include <stack>
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

// Given a root binary tree and the task is to find the spiral order traversal
// of the tree and return the list containing the elements. Spiral Order
// Traversal mean: Starting from level 0 for root node, for all the even levels
// we print the node's value from right to left and for all the odd levels we
// print the node's value from left to right.
// ----------------------------------------------------------------------------
// To traverse in spiral level order we have to use two stacks(we can also use 1
// queue and 1 stack but we have to reverse queue after every iteration) beacuse
// we have to change direction after every iteration of level treverse.
// Stack 1 keep track of direction right -> left.
// Stack 2 keep track of direction left -> right.

vector<int> levelOrderSpiralTraversal(Node *root) {
  stack<Node *> s1;
  stack<Node *> s2;
  vector<int> ans;
  Node *temp;
  s1.push(root);

  while (!s1.empty() || !s2.empty()) {
    if (!s1.empty()) {
      while (!s1.empty()) {
        temp = s1.top();
        ans.push_back(temp->data);
        s1.pop();
        // here order matter for right and left because in s2 we want to push
        // right node first and then left one because then in s2 iteration s2
        // get leftmost first.
        if (temp->right) {
          s2.push(temp->right);
        }
        if (temp->left) {
          s2.push(temp->left);
        }
      }
    }
    if (!s2.empty()) {
      while (!s2.empty()) {
        temp = s2.top();
        ans.push_back(temp->data);
        s2.pop();
        // here order matter for left and right because in s1 we want to push
        // left node first and then right one because then in s1 iteration s1
        // get rightmost first.
        if (temp->left) {
          s1.push(temp->left);
        }
        if (temp->right) {
          s1.push(temp->right);
        }
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
  levelOrderSpiralTraversal(root);
  return 0;
}
