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
//
// Note:- I haven't take the edge cases.
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

// In this we simply move head to its next pointer and then simply delete it.
void deleteAtStart() {
  if (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;

    if (head)
      head->pre = nullptr;
  }
}

// To delete at end we first traverse the list to end and then for current's
// next's previous will become nullptr as now it is end. Then we just delete
// current.
void deleteAtEnd() {
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    Node *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->pre->next = nullptr;
    delete curr;
  }
}

// To delete at any position we simply traverse to that point and then just
// update the next of current's previous and the pre of current's next. Then we
// just simply delete it.
//
// Note:- I haven't take the edge cases.
void deleteAtPosition(int pos) {
  Node *curr = head;
  while (pos--) {
    curr = curr->next;
  }
  curr->pre->next = curr->next;
  curr->next->pre = curr->pre;
  delete curr;
}
