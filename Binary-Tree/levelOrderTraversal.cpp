#include <iostream>
#include <queue>
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

// In Level Order trversal we move level wise
//               2               ->travel 2
//          3         7          ->travel 3->7
//       5     9   10    1       ->travel 5->9->10->1
//     6   9      8              ->travel 6->9->8
//
// Final traversal:- 2 3 7 5 9 10 1 6 9 8

void levelOrderTraversal(Node *root) {
  queue<Node *> q;
  q.push(root);
  Node *temp;
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    cout << temp->data << " ";
    if (temp->left) {
      q.push(temp->left);
    }
    if (temp->right) {
      q.push(temp->right);
    }
  }
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
  levelOrderTraversal(root);
  return 0;
}
