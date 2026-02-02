#include <cstdlib>
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

// Given the root of a Binary Tree, find the vertical traversal of the tree
// starting from the leftmost level to the rightmost level.

// Note: If there are multiple nodes passing through a vertical line, then they
// should be printed as they appear in level order traversal of the tree.
//--------------------------------------------------------------------------
// To solve this problem we take same apporoach as in top view, just this time
// we not just push top level but now we first store temp->data in level-wise in
// an array.

void findExtream(Node *root, int pos, int &l, int &r) {
  if (root == nullptr) {
    return;
  }
  l = min(pos, l);
  r = max(pos, r);

  findExtream(root->left, pos - 1, l, r);
  findExtream(root->right, pos + 1, l, r);
}

vector<vector<int>> verticalTraversal(Node *root) {
  int l = 0, r = 0;
  findExtream(root, 0, l, r);
  vector<vector<int>> posotive(r + 1);
  vector<vector<int>> negative(abs(l) + 1);
  queue<Node *> q;  // keep check of traversal
  queue<int> index; // keep track of pos so we find out level.
  Node *temp;
  int pos;
  vector<vector<int>> ans;
  q.push(root);
  index.push(0);
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    pos = index.front();
    index.pop();

    if (pos >= 0) {
      posotive[pos].push_back(temp->data); // level-wise storing of data.
    } else {
      negative[pos].push_back(temp->data); // level-wise storing of data.
    }

    if (temp->left) {
      q.push(temp->left);
      index.push(pos - 1);
    }
    if (temp->right) {
      q.push(temp->right);
      index.push(pos + 1);
    }
  }
  for (int i = negative.size() - 1; i > 0; i--) {
    ans.push_back(negative[i]);
  }
  for (int i = 0; i < posotive.size(); i++) {
    ans.push_back(posotive[i]);
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
