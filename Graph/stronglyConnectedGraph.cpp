#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Strongly Connected Components (SCCs) are maximal subgraphs of a directed graph where every vertex is reachable from every other vertex within that subgraph. They represent isolated, tightly-knit cycles in a graph, and are determined using linear time complexity algorithms like Kosaraju's algorithm or Tarjan's algorithm.
//
// Strongly Connected Components have property that if we reversed each and ervey edge's direction then also they will be Strongly Connected Components.
// 
// ---------------- METHOD-1 --------------------
// Kosaraju Algorithm:-
// 1. Do topological sort.
// 2. Reverse the edges of the graph.
// 3. Pop the element from the stack and if it is not visited:-
//       i. increase Strongly Connected graph count by 1.
//       ii. Do DFS traversal.

void DFS1(int node,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st){
    visited[node] = 1;

    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            DFS1(adj[node][i],adj,visited,st);
        }
    }
    st.push(node);
}

void DFS2(int node,vector<vector<int>> &adj,vector<bool> &visited){
    visited[node] = 1;

    for(int i=0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            DFS2(adj[node][i],adj,visited);
        }
    }
}

int kosarajuAlgo(vector<vector<int>> &adj){
    int V = adj.size();
    vector<bool> visited(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS1(i,adj,visited,st);
        }
    }
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }

    vector<vector<int>> reverseAjd(V);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            int node = adj[i][j];
            reverseAjd[node].push_back(i);
        }
    }

    int count = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            DFS2(node,reverseAjd,visited);
            count++;
        }
    }

    return count;
}

int main(){
    vector<vector<int>> adj = {{2,3},{0},{1},{4},{}};
    cout<<"Strongly Connected Components in a given graph is "<<kosarajuAlgo(adj)<<"\n";
    return 0;
}
