#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(int i,int j,int n){
    return i>=0 && j>=0 && j<n && i<n;
}

void totalPaths(vector<vector<int>>& maze,int i,int j,int n,string path,vector<string>& ans,vector<vector<int>>& visited){
    int rows[] = {-1,1,0,0};
    int cols[] = {0,0,-1,1};
    string dir = "UDLR";
    if(i==n-1 && j ==n-1){
        ans.push_back(path);
        return;
    }
    visited[i][j] = 1;

    for(int k = 0;k<4;k++){
        if(isValid(i+rows[k],j+cols[k],n) && maze[i+rows[k]][j+cols[k]] && !visited[i+rows[k]][j+cols[k]]){
            path.push_back(dir[k]);
            totalPaths(maze,i+rows[k],j+cols[k],n,path,ans,visited);
            path.pop_back();
        }
    }
    visited[i][j] = 0;

}

int main(){
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> visited = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    vector<string> ans;
    string path;
    totalPaths(maze,0,0,4,path,ans,visited);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
