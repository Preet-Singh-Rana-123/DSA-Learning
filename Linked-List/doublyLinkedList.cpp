#include <iostream>
using namespace std;

// Doubly linked list is type of linked list which also store the address of
// previous node with next node. So, that traversal from both side possible.
class Node {
public:
  int data;
  Node *next;
  Node *pre;

  Node(int value) {
    this->data = value;
    this->next = nullptr;
    this->pre = nullptr;
  }
};

Node *head;

// just like singlly we insert at start, but now we also need to keep check of
// previous node pointer.
//
// For that we first create temp node and then link its next to head pointer and
// then we also link head pointers's pre to temp. And, then we simply make temp
// as head.
void insertAtBegining(int val) {
  if (head == nullptr) {
    head = new Node(val);
  } else {
    Node *temp = new Node(val);
    temp->next = head;
    head->pre = temp;
    head = temp;
  }
}

// Insertion at end also same like singlly linked list first we travers to last
// of linked list and then add new node to it.
void insertAtEnd(int val) {
  if (head == nullptr) {
    head = new Node(val);
  } else {
    Node *curr = head;
    while (curr) {
      curr = curr->next;
    }
    Node *temp = new Node(val);
    curr->next = temp;
    temp->pre = curr;
  }
}

// In this case we first travers to that position and then we make temp->next to
// curr->next and temp->pre to curr. After this we make curr->next to temp. Also
// now we also have to update temp->next->pre to temp so that it now point to
// temp not curr.
void insertionAtPosition(int pos, int val) {
  Node *temp = new Node(val);
  Node *curr = head;
  while (pos--) {
    curr = curr->next;
  }
  temp->next = curr->next;
  temp->pre = curr;
  curr->next = temp;
  temp->next->pre = temp;
}
