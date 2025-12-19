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

// This function will add the data at the start of the linked list.
//
// For add at start we will create a temp pointer of Node which will create a
// node and then we add it to the start.
//
// For adding at start we will first put head pointer in the next of temp
// (temp->next) and then we simply move the head pointer to temp pointer so that
// now temp will become head.
void insertAtBegining(int value) {
  // This is condition for when head is not storing any address of Node.
  if (head == nullptr) {
    head = new Node(value);
  } else {
    Node *temp;
    temp = new Node(value);
    temp->next = head;
    head = temp;
  }
}

// To insert node at the end of linked-list we simply traverse to the point
// where node's next is nullptr and then at that we simply store the value of
// out node pointer (temp).
//
// Keep in mind that we will not move head as it is storing the stating of
// linked-list and if we we move it ther is no going back of head and therefore
// we lost the value of our linked-list starting. Therefore we will create a
// tail pointer that will store head and then we move that tail to get to the
// end of linked-list.
void insertAtEnd(int value) {
  if (head == nullptr) {
    head = new Node(value);
  } else {
    Node *temp = new Node(value);
    Node *tail = head;

    while (tail->next != nullptr) {
      tail = tail->next;
    }

    tail->next = temp;
  }
}

// To insert element at any position of linked list first we travel to that
// posion and then create a node that will contain that value and then simply
// join it at that point.
//
// To join it we simply made a tail pointer that will travel to that posion and
// then we store node's next(temp->next) to tail's next and then we store tail's
// next to temp.
void insertAtPosition(int pos, int value) {
  Node *temp = new Node(value);
  Node *tail = head;
  pos--;

  while (pos--) {
    tail = tail->next;
  }
  temp->next = tail->next;
  tail->next = temp;
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

  insertAtEnd(4);
  insertAtEnd(5);

  insertAtPosition(3, 10);

  printLinkedList();
  return 0;
}
