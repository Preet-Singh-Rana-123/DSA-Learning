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

// To reverse a linked list we follow some steps:-
// 1. we make a curr pointer which has head and we also make prev pointer which
// store the address of previous of current and future pointer which store the
// address of curr->next;
// 2. now first we store the value of curr->next to future.
// 3. then we store value of prev in the curr->next so now it direct to
// backword.
// 4. then we store value of curr in the prev.
// 5. then we put value of future in curr to move forward.
//
// After the loop end we simply move the location head to prev which is holding
// address of least node.
//
// Now, list is reversed.
void reverseLinkedList() {
  Node *curr = head;
  Node *prev = nullptr;
  Node *future = nullptr;
  while (curr) {
    future = curr->next;
    curr->next = prev;
    prev = curr;
    curr = future;
  }
  head = prev;
}

int main() {
  insertAtBegining(1);
  insertAtBegining(2);
  insertAtBegining(3);
  insertAtBegining(4);
  insertAtBegining(5);
  insertAtBegining(6);

  cout << "Original Linked-List: ";
  printLinkedList();

  reverseLinkedList();
  cout << "\nAfter reversing: ";
  printLinkedList();
  return 0;
}
