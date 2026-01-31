#include <iostream>
#include <queue>
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

// Given the root of a binary tree. Your task is to return the left view of the
// binary tree. The left view of a binary tree is the set of nodes visible when
// the tree is viewed from the left side.

// Note: If the tree is empty, return an empty list.
// ----------------------------------------------------------------------------
// To solve this problem we will travel level order and now instead of pushing
// every temp->data into ans vector we only push left->data.
// For that we will maintain size of queue as it is storing value of one level
// in one iteration. Therefore after pushing current level's all node into queue
// we will just push_back queue's front's data into ans vector.

vector<int> leftView(Node *root) {
  queue<Node *> q;
  vector<int> ans;
  int n;
  Node *temp;
  q.push(root);

  while (!q.empty()) {
    ans.push_back(q.front()->data); // pushing only front's data into ans as its the leftmost.
    n = q.size();            // n for only first traversing current level before entring next level. 
    while (n--) {
      temp = q.front();
      q.pop();
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
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
