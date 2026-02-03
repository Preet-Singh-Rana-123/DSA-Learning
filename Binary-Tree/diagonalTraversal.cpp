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

// Given a Binary Tree, return the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, return
// a single list containing all diagonal elements in a binary tree belonging to
// same line. If the diagonal element are present in two different subtrees then
// left subtree diagonal element should be taken first and then right subtree.
// -----------------------------------------------------------------------
// To solve this problem we will store the node's data in a matrix that store
// data level wise.
// If observe it we can see that for same left level, they form daigonal. So for
// same left level we store them in their respective ans level.
//                6 (l:0,r:0)
//          9 (l:1,r:0)    3 (l:0,r:1)
//      4 (l:2,r:0)   1 (l:1,r:1)   2 (l:0,r:1)
//  6 (l:3,r:0)

void findLeftExtream(Node *root, int &l, int pos) {
  if (root == nullptr) {
    return;
  }

  l = max(l, pos);
  findLeftExtream(root->left, l, pos + 1);
  findLeftExtream(root->right, l, pos);
}

void findDaigonal(Node *root, int level, vector<vector<int>> &ans) {
  if (root == nullptr) {
    return;
  }

  ans[level].push_back(root->data);
  findDaigonal(root->left, level + 1, ans);
  findDaigonal(root->right, level, ans);
}

vector<int> daigonalTraversal(Node *root) {
  int l = 0;
  findLeftExtream(root, l, 0);

  vector<vector<int>> ans(l + 1);
  findDaigonal(root, 0, ans);

  vector<int> realAns;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      realAns.push_back(ans[i][j]);
    }
  }

  return realAns;
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
