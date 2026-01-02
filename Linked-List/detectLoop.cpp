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

//------- 1st METHOD --------

// This is unordered_map method. In this we create a unordered_map make with key
// as visited Nodes and value as boolean which keep track if that node is
// visited or not. If node is visited then we simply return 1 ans if not visited
// then we set visited[curr] as 1 to show that now it is visited. If loop does
// not encounter any loop then simply return 0;
bool isLoop() {
  Node *curr = head;
  unordered_map<Node *, bool> visited;

  while (curr != nullptr) {
    if (visited[curr] == 1) {
      return 1;
    }
    visited[curr] = 1;
    curr = curr->next;
  }
  return 0;
}

//------ 2nd METHOD ----------

// This is slow pointer and fast pointer method in which slow move one step and
// fast move two steps. Therefore in a loop there will be a point when slow and
// fast meet and if they meet means there is loop, else fast move upto last and
// there in no loop.
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
    cout << "Linked List: ";
    printLinkedList();
  }

  return 0;
}
