#include <iostream>
#include <unordered_map>
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

bool detectLoop() {
  Node *fast = head;
  Node *slow = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return 1;
    }
  }
  return 0;
}

void printLinkedList() {
  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// To remove loop from linked list we first find the node that started the loop
// and then we simply make its next as nullptr.
//
// Firstly we store the data of visited nodes in a unordered_map and traverse
// the whole linked list. Then once the visited[curr] become 1 means we already
// in loop and now the previous of curr node we be the starting point of loop.
// So we just make next of previous as nullptr.
void removeLoop() {
  Node *curr = head;
  Node *prev = nullptr;
  unordered_map<Node *, bool> visited;

  while (curr != nullptr) {
    if (visited[curr] == 1) {
      break;
    }
    visited[curr] = 1;
    prev = curr;
    curr = curr->next;
  }
  prev->next = nullptr;
}

int main() {
  head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(7);
  head->next->next->next->next->next->next->next = new Node(9);
  head->next->next->next->next->next->next->next->next = new Node(10);
  head->next->next->next->next->next->next->next->next->next =
      head->next->next->next;

  if (detectLoop()) {
    cout << "There is loop in Linked List.";
  } else {
    cout << "There is no loop in Linked List: ";
    printLinkedList();
  }

  removeLoop();
  cout << "\nLinked list after removing loop: ";
  printLinkedList();

  return 0;
}
