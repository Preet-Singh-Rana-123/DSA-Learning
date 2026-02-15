#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// You are given an integer n, which indicates that there are n courses labeled
// from 1 to n. You are also given a 2D integer array relations where
// relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has
// to be completed before course nextCoursej (prerequisite relationship).
// Furthermore, you are given a 0-indexed integer array time where time[i]
// denotes how many months it takes to complete the (i+1)th course.

// You must find the minimum number of months needed to complete all the courses
// following these rules:

// You may start taking a course at any time if the prerequisites are met.
// Any number of courses can be taken at the same time.
// Return the minimum number of months needed to complete all the courses.

// Note: The test cases are generated such that it is possible to complete every
// course (i.e., the graph is a directed acyclic graph).
// ------------------------------------------------------------------------------
// To solve this problem if we see clearly it uses the concept of topological
// sort.

int findTime(int n, vector<vector<int>> &relations, vector<int> &time) {
  // creating adj list
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
  }
  // creating list of incoming node list in inDeg array for khan's algo
  vector<int> inDeg(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      inDeg[adj[i][j]]++;
    }
  }
  queue<int> q;
  vector<int> courseTime(n, 0); // this array will keep track of taken by nodes
                                // to reach neighbour node.
  for (int i = 0; i < n; i++) {
    if (inDeg[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int i = 0; i < adj[node].size(); i++) {
      inDeg[adj[node][i]]--;
      if (inDeg[adj[node][i]] == 0) {
        q.push(adj[node][i]);
      }

      // here we updating neighbour node's time to complete by taking max b/w
      // time take by other node to reach same neighbour and time take by node
      // to reach node + what time now node take to complete.
      courseTime[adj[node][i]] =
          max(courseTime[node] + time[node], courseTime[adj[node][i]]);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, courseTime[i] + time[i]);
  }

  return ans;
}

int main() {
  vector<vector<int>> relations = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
  vector<int> time = {1, 2, 3, 4, 5};

  cout << "Time taken to complete course: " << findTime(5, relations, time)
       << "\n";
  return 0;
}
