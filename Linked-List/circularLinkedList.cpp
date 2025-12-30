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

void insertAtBegining(Node *&head, Node *&tail, int value) {
  Node *newNode = new Node(value);
  if (tail == nullptr) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }
  newNode->next = tail->next;
  tail->next = newNode;
  head = tail->next;
}

void insertAtEnd(Node *&tail, int value) {
  Node *newNode = new Node(value);
  if (tail == nullptr) {
    newNode->next = newNode;
    tail = newNode;
    return;
  }
  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
}

void deleteFromStart(Node *&tail) {
  if (tail == nullptr) {
    cout << "List is empty";
    return;
  }

  Node *head = tail->next;

  if (head == tail) {
    delete tail->next;
    tail = nullptr;
    return;
  }
  tail->next = head->next;
  delete head;
}

void deleteFromEnd(Node *&tail) {
  if (tail == nullptr) {
    cout << "List is empty";
    return;
  }

  Node *head = tail->next;

  if (head == tail) {
    delete tail->next;
    tail = nullptr;
    return;
  }

  Node *curr = head;
  while (curr->next != tail) {
    curr = curr->next;
  }
  curr->next = head;
  delete tail;
  tail = curr;
}

void printList(Node *head) {
  Node *temp = head;
  cout << temp->data << " ";
  temp = temp->next;
  while (temp != head) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);

  head->next->next->next->next->next->next = head;

  Node *tail = head;

  while (tail->next != head) {
    tail = tail->next;
  }

  cout << "Original List: ";
  printList(head);

  insertAtBegining(head, tail, 7);
  insertAtBegining(head, tail, 8);

  cout << "\nAfter insertion: ";
  printList(head);

  return 0;
}
