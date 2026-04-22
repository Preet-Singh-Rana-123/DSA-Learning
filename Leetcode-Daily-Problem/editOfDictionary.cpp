#include <iostream>
#include <string>
#include <vector>
using namespace std;

// You are given two string arrays, queries and dictionary. All words in each
// array comprise of lowercase English letters and have the same length.

// In one edit you can take a word from queries, and change any letter in it to
// any other letter. Find all words from queries that, after a maximum of two
// edits, equal some word from dictionary.

// Return a list of all words from queries, that match with some word from
// dictionary after a maximum of two edits. Return the words in the same order
// they appear in queries.
// ------------------------------------------------------------------------------
// Just Brute-Force it with checking difference on unmatched character and if
// its in provided range then add it to ans array

vector<string> twoEditWords(vector<string> &queries,
                            vector<string> &dictionary) {
  vector<string> ans;
  for (auto q : queries) {
    for (auto s : dictionary) {
      int diff = 0;
      for (int i = 0; i < q.size(); i++) {
        if (s[i] != q[i]) {
          diff++;
        }
        if (diff > 2) {
          break;
        }
      }
      if (diff <= 2) {
        ans.push_back(q);
        break;
      }
    }
  }
  return ans;
}

int main() {
  vector<string> queries = {"word", "note", "ants", "wood"};
  vector<string> dictionary = {"wood", "joke", "moat"};
  vector<string> ans = twoEditWords(queries, dictionary);
  for (auto s : ans) {
    cout << s << " ";
  }
  cout << "\n";
  return 0;
}
