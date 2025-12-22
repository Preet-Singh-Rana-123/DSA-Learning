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

// Here to find the midle of linked list we use the concept of fast and slow
// pointer.
//
// First we make two pointer slow(move one at a step) and fast(move two at a
// step). Then we move fast pointer until it became NULL or its fast->next
// became null. By making fast move twice and slow move once we can get slow at
// middle when fast reached the end.
Node *middleLinkedList() {
  Node *fast = head;
  Node *slow = head;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

int main() {
  insertAtBegining(1);
  insertAtBegining(2);
  insertAtBegining(3);
  insertAtBegining(4);
  insertAtBegining(5);
  insertAtBegining(6);

  cout << "Original Linked list: ";
  printLinkedList();
  head = middleLinkedList();
  cout << "\nLinked list from middle: ";
  printLinkedList();
  return 0;
}
