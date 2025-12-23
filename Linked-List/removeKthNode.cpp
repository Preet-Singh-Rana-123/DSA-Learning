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
  if (head == nullptr) {
    cout << "No element in linked list";
    return;
  }
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// To delete every kth elemnt we simply traverse whole linked list and delete
// the kth term. To de that we we follow following steps:
// Step 1: We create curr pointer to store current value and a prev pointer to
// store previous node.
//
// Step 2: Then we create a count variable and we increase it on every loop.
//
// Step 3: Now if count == k then, we simply delete that curr pointer. Otherwise
// we simply move curr and prev pointer.
void removeKthNode(int k) {
  Node *curr = head;
  Node *prev = nullptr;
  int count = 0;

  if (k == 1) {
    delete head;
  }

  while (curr) {
    count++;
    if (count == k) {
      Node *temp = curr;
      prev->next = curr->next;
      curr = curr->next;
      delete temp;
      count = 0;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
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

  cout << "Before removing: ";
  printLinkedList();

  removeKthNode(3);
  cout << "\nAfter removing: ";
  printLinkedList();
  return 0;
}
