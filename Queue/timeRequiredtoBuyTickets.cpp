#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// There are n people in a line queuing to buy tickets, where the 0th person is
// at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number
// of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1
// ticket at a time and has to go back to the end of the line (which happens
// instantaneously) in order to buy more tickets. If a person does not have any
// tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to
// finish buying tickets.
// ------------------------------------------------------------------------------
// To solve this problem we use queue because we need to served persons in front
// of line and if he want more ticket then he has to join line again from last.
// For that we first store queue of indexes of persons in array, then decrease
// tickets[queue's front] by one and then check if he wants more tickets then we
// push him to last and pop him from front. Also we increase the time. We will
// do this until our specified person get all tickets he wants.

int timeRequiredToBuy(vector<int> &tickets, int k) {
  queue<int> q;
  for (int i = 0; i < tickets.size(); i++) {
    q.push(i);
  }
  int time = 0;
  while (tickets[k]) {
    tickets[q.front()]--;
    if (tickets[q.front()])
      q.push(q.front());
    q.pop();
    time++;
  }
  return time;
}

int main() {
  vector<int> tickets = {5, 1, 1, 1};
  cout << "Time required to buy tickets: " << timeRequiredToBuy(tickets, 0)
       << "\n";
  return 0;
}
