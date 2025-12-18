#include <iostream>
using namespace std;

// Linked list is like data structure to store data in linear way where every
// node is connected to next node by storing address of next node.
//
// Node mainly consist of data(stores value which we want to store) and
// next(pointer to next node).
//
// Head is basicaly entry list of linked list, it is reference to very first
// node.
// Keep in mind that head is not node, it is ponter to the node that is
// storing value that we want to store and head is just point that is storing
// the address of that node.

class Node {
public:
  int data;
  Node *next;

  Node(int value) {
    this->data = value;
    this->next = nullptr;
  }
};

int main() {
  Node *head;
  head = new Node(5);
  return 0;
}
