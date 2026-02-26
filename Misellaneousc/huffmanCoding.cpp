#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Huffman coding is a lossless data compression algorithm. The idea is to
// assign variable-length codes to input characters, lengths of the assigned
// codes are based on the frequencies of corresponding characters.
//
// There are mainly two major parts in Huffman Coding:
// 1. Build a Huffman Tree from input characters.
// 2. Traverse the Huffman Tree and assign codes to characters.
//
// Steps to build Huffman Tree:
// This algorithm builds a tree in bottom up manner using a priority queue (or
// heap). Input is an array of unique characters along with their frequency of
// occurrences and output is Huffman Tree.

// 1. Create a leaf node for each unique character and build a min heap of all
// leaf nodes (Min Heap is used as a priority queue. The value of frequency
// field is used to compare two nodes in min heap. Initially, the least frequent
// character is at root)
// 2. Extract two nodes with the minimum frequency from the min heap.
// 3. Create a new internal node with a frequency equal to the sum of the two
// nodes frequencies. Make the first extracted node as its left child and the
// other extracted node as its right child. Add this node to the min heap.
// 4. Repeat steps#2 and #3 until the heap contains only one node. The remaining
// node is the root node and the tree is complete.

class Node {
public:
  int freq;
  char c;
  Node *left, *right;

  Node(int frequency, char character) {
    freq = frequency;
    c = character;
    left = right = nullptr;
  }
};

class Compare {
public:
  bool operator()(Node *a, Node *b) { return a->freq > b->freq; }
};

void preorder(Node *root, string &temp, vector<string> &ans) {
  if (root == nullptr) {
    return;
  }
  if (!root->left && !root->right) {
    ans.push_back(temp);
    return;
  }

  temp.push_back('0');
  preorder(root->left, temp, ans);
  temp.pop_back();
  temp.push_back('1');
  preorder(root->right, temp, ans);
  temp.pop_back();
}

vector<string> huffmanCodes(string s, vector<int> f) {
  int n = s.length();

  priority_queue<Node *, vector<Node *>, Compare> pq;
  for (int i = 0; i < n; i++) {
    pq.push(new Node(f[i], s[i]));
  }

  while (pq.size() > 1) {
    Node *first = pq.top();
    pq.pop();
    Node *second = pq.top();
    pq.pop();

    Node *temp = new Node(first->freq + second->freq, '$');
    temp->left = first;
    temp->right = second;
    pq.push(temp);
  }

  Node *root = pq.top();
  pq.pop();

  vector<string> ans;
  string temp;
  preorder(root, temp, ans);

  return ans;
}

int main() {
  string s = "abcdef";
  vector<int> freq = {5, 9, 12, 13, 16, 45};
  vector<string> ans = huffmanCodes(s, freq);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
