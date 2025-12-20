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

// For deletion at start we simply create a temp pointer and store the head in
// it and then we move head to next node by simply putting value of head->next
// in it. Then we just delete the temp from memory using delete.
void deleteAtStart() {
  if (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

// To delete a element from the end of linked list we simply move to last of
// linked list and then just delete it, But before deleting it we have to store
// the value of previous node address of last node becauuse now that previous
// one became the last element so then its needs to hace nullptr in its next,
// therefore we need to keep the track of previous element also before moving
// the current.
void deleteAtEnd() {
  // Case where ther is only one element in inked list
  if (head->next == nullptr) {
    Node *temp = head;
    head = nullptr;
    delete temp;
  }
  Node *curr = head;
  Node *prev = nullptr;
  while (curr->next != nullptr) {
    prev = curr;
    curr = curr->next;
  }
  delete curr;
  prev->next = nullptr;
}

// To delete the element from the give position we would simply travel to that
// postion and then delete it. But, before traveling we also track the previous
// node also so that we can update its next with the next of node at that
// position.
void deleteAtPosition(int pos) {
  // Condition when we have delete from first position
  if (pos == 1) {
    Node *temp = head;
    head = head->next;
    delete temp;
  } else {
    Node *curr = head;
    Node *prev = nullptr; // keep the track of previous node
    pos--;
    while (pos--) {
      prev = curr; // store the previous node as curr because now we are going
                   // to move curr to curr->next.
      curr = curr->next; // move curr to next node.
    }
    prev->next =
        curr->next; // store the value of next of curr in the next of prev to
                    // connect them as now curr is going to delete.
    delete curr;
  }
}

void printLinkedList() {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  insertAtBegining(1);
  insertAtBegining(2);
  insertAtBegining(3);
  insertAtBegining(4);
  insertAtBegining(5);
  insertAtBegining(6);
  insertAtBegining(7);

  cout << "Before deletion: ";
  printLinkedList();

  deleteAtStart();
  cout << "\nAfter deletion from start: ";
  printLinkedList();

  deleteAtEnd();
  cout << "\nAfter deletion from start: ";
  printLinkedList();

  deleteAtPosition(2);
  cout << "\nAfter deletion from postion 2: ";
  printLinkedList();
  return 0;
}
