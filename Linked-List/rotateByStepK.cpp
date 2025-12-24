#include <iostream>
using namespace std;

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
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// To rotate a list by kth setp we simply move to kth place from end and then
// just break it and join it with the head.
//
// Step 1: we create a curr pointer, prev pointer for deleting and tail pointer
// to join it to the end.
//
// Step 2: first we move the tail pointer to the end and also keek the count of
// leangth of linked-list
//
// Step 3: now we just subtract k from count to get from where we have to remove
// our curr pointer.
//
// Step 4: after subtracting k from count we get the steps we have to move to
// remove and join to head. Now we keep the track of curr pointer and prev
// pointer also.
//
// Step 5: now as after removing prev became last element so we make its next to
// NULL.
//
// Step 5: then we move tail's next to head and move head to curr as it is new
// head after rotation.
void rotateByStepK(int k) {
  // condition where head is NULL or linked list only have one element or we
  // have to rotate at k = 1. In all case we just return nead as there is no
  // change in linked list occurr.
  if (k == 1 || !head || !head->next) {
    return;
  }
  Node *curr = head;
  Node *tail = head;
  Node *prev = nullptr;
  int count = 1;

  while (tail->next) {
    tail = tail->next;
    count++;
  }

  // case where we have k more than length of linked list.
  k = k % count;
  if (k == 0) {
    return;
  }

  count = count - k;

  while (count--) {
    prev = curr;
    curr = curr->next;
  }
  prev->next = nullptr;
  tail->next = head;
  head = curr;
}

int main() {
  insertAtBegining(10);
  insertAtBegining(9);
  insertAtBegining(8);
  insertAtBegining(7);
  insertAtBegining(6);
  insertAtBegining(5);
  insertAtBegining(4);
  insertAtBegining(3);
  insertAtBegining(2);
  insertAtBegining(1);

  cout << "Befor rotation: ";
  printLinkedList();

  rotateByStepK(4);
  cout << "\nAfter rotation: ";
  printLinkedList();

  return 0;
}
