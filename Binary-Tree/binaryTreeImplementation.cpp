#include <iostream>
#include <queue>
using namespace std;

// Tree is a data structure that store data in a hirarchial relationship between
// data elements called nodes.
//
// Binary Tree:- its a type of data structure which has atmost 2 children.

class Node {
public:
  int data;
  Node *left, *right;

  Node(int x) {
    this->data = x;
    this->left = this->right = nullptr;
  }
};

int main() {
  int x;
  cin >> x;
  queue<Node *> q;
  Node *root = new Node(x);
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();
    cin >> x;
    if (x != -1) {
      temp->left = new Node(x);
      q.push(temp->left);
    }
    cin >> x;
    if (x != -1) {
      temp->right = new Node(x);
      q.push(temp->right);
    }
  }

  return 0;
}
