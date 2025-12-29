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

void insertAtBegining(Node *&head, int value) {
  if (head == nullptr) {
    head = new Node(value);
  } else {
    Node *temp;
    temp = new Node(value);
    temp->next = head;
    head = temp;
  }
}

void printLinkedList(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// To merge teo sorted linked list we follow apporoach linke putting pointer on
// start of both linked list and then compare them and then whoever is small
// comes first and pointer move forward. We will do this until one linked list
// is completed and then just simply attch remaining from other list to our
// merged list.
Node *mergeSortedLinkedList(Node *&head1, Node *&head2) {
  Node *head = new Node(0);
  Node *tail = head;

  while (head1 && head2) {
    if (head1->data <= head2->data) {
      tail->next = head1;
      tail = tail->next;
      head1 = head1->next;
      tail->next = nullptr;
    } else {
      tail->next = head2;
      tail = tail->next;
      head2 = head2->next;
      tail->next = nullptr;
    }
  }
  if (head1) {
    tail->next = head1;
  } else {
    tail->next = head2;
  }

  head = head->next;

  return head;
}

int main() {
  Node *head1 = nullptr;
  Node *head2 = nullptr;

  insertAtBegining(head1, 8);
  insertAtBegining(head1, 5);
  insertAtBegining(head1, 3);
  insertAtBegining(head1, 2);
  insertAtBegining(head1, 1);

  insertAtBegining(head2, 9);
  insertAtBegining(head2, 7);
  insertAtBegining(head2, 4);

  cout << "List 1: ";
  printLinkedList(head1);
  cout << "\nList 2: ";
  printLinkedList(head2);
  cout << "\nList after merging: ";
  Node *head = mergeSortedLinkedList(head1, head2);
  printLinkedList(head);

  return 0;
}
