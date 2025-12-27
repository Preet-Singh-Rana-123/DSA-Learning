#include <iostream>
using namespace std;

// Problem Statement: Given a singly linked list. The task is to remove
// duplicates (nodes with duplicate values) from the given list (if it exists).

class Node {
public:
  int data;
  Node *next;

  Node(int value) {
    this->data = value;
    this->next = nullptr;
  }
};

Node *head;

void insertAtBegining(int value) {
  if (head == nullptr) {
    head = new Node(value);
  } else {
    Node *temp;
    temp = new Node(value);
    temp->next = head;
    head = temp;
  }
}

void printLinkedList() {
  Node *temp = head;
  if (head == nullptr) {
    cout << "No element in linked list";
    return;
  }
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// To remove duplicate from linked list we follow following steps.
//
// Step 1: firstly we create curr pointer which will travers through linked
// list.
//
// Step 2: Then we check if curr->data == curr->next->data.
//
// Step3: If it is equal then firstly we make a duplicate node pointer which
// will store curr->next value as curr->next->data == curr->next. Then we simply
// move curr->next to curr->next->next and then delete duplicate value.
//
// Step 4: After this loop again follow because curr->next != nullptr. And again
// check for if curr->data == curr->next->data and if it is yes then again step
// 3 and then step 4.
//
// Step 5: If curr->data != curr->next->data then we simply move curr to
// curr->next as now next value is not duplicate so, for next time it will will
// check for new value if its next is duplicate or not.
void removeDuplicate() {
  Node *curr = head;
  while (curr->next != nullptr) {
    if (curr->data == curr->next->data) {
      Node *duplicate = curr->next;
      curr->next = curr->next->next;
      delete duplicate;
    } else {
      curr = curr->next;
    }
  }
}

int main() {

  insertAtBegining(6);
  insertAtBegining(6);
  insertAtBegining(6);
  insertAtBegining(5);
  insertAtBegining(5);
  insertAtBegining(4);
  insertAtBegining(3);
  insertAtBegining(3);
  insertAtBegining(2);
  insertAtBegining(1);
  insertAtBegining(1);

  cout << "Original linked list: ";
  printLinkedList();
  cout << "\nList after removing duplicate: ";
  removeDuplicate();
  printLinkedList();

  return 0;
}
