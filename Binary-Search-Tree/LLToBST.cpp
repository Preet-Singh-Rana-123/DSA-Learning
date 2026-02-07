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

class LNode {
public:
  int data;
  LNode *next;

  LNode(int x) {
    this->data = x;
    this->next = nullptr;
  }
};

// Given a Singly Linked List which has data members sorted in ascending order.
// Construct a Balanced Binary Search Tree which has same data members as the
// given Linked List.
// Note: There might be nodes with the same value.
//-------------------------------------------------------------------------
// To solve this problem we simple create an array and store linked list data
// into that array and then we simply create BST using array.

Node *createBST(vector<int> &arr, int start, int end) {
  if (start > end) {
    return nullptr;
  }

  int mid = start + (end - start) / 2;
  Node *root = new Node(arr[mid]);
  root->left = createBST(arr, start, mid - 1);
  root->right = createBST(arr, mid + 1, end);

  return root;
}

Node *linkedListToBST(LNode *head) {
  vector<int> ans;
  while (head) {
    ans.push_back(head->data);
    head = head->next;
  }

  return createBST(ans, 0, ans.size() - 1);
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
