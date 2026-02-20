#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Given an array arr of lowercase strings, determine if the strings can be
// chained together to form a circle. A string X can be chained together with
// another string Y if the last character of X is the same as the first
// character of Y. If every string of the array can be chained with exactly two
// strings of the array(one with the first character and the second with the
// last character of the string), it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer
// will be Yes as the given strings can be chained as "for", "rig", "geek" and
// "kaf"
// ------------------------------------------------------------------------
// To solve this problem we have form a adjancy list with strings 0 index
// connected with stings last index. Now if that adjancy list form a eulerian
// circuit then there is circle of string.

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) {
  visited[node] = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    if (!visited[adj[node][i]]) {
      DFS(adj[node][i], adj, visited);
    }
  }
}

bool isCircle(vector<string> &arr) {
  int n = arr.size();
  vector<vector<int>> adj(26);
  vector<int> inDeg(26, 0);
  vector<int> outDeg(26, 0);
  // forming adj list with strings 0 connected with last index
  for (int i = 0; i < n; i++) {
    string temp = arr[i];
    int u = temp[0] - 'a';
    int v = temp[temp.size() - 1] - 'a';
    adj[u].push_back(v);
    outDeg[u]++;
    inDeg[v]++;
  }

  // if inDeg != outDeg for node then their is no eulerian circuit.
  for (int i = 0; i < 26; i++) {
    if (inDeg[i] != outDeg[i]) {
      return false;
    }
  }

  vector<bool> visited(26, 0);
  int node = arr[0][0] - 'a';
  DFS(node, adj, visited);

  // checking if graph is connected of not for eulerian circuit.
  for (int i = 0; i < 26; i++) {
    if (inDeg[i] && !visited[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  vector<string> arr = {"abc", "bcd", "cdf", "fab", "dca"};
  if (isCircle(arr)) {
    cout << "Yes it form a circle.\n";
  } else {
    cout << "Not it does not form a circle.\n";
  }
  return 0;
}
