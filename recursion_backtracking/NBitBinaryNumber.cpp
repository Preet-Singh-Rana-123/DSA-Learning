#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findNBitBinary(int n,vector<string>& ans,string& temp,int zero,int ones){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    if(zero<ones){
        temp.push_back('0');
        findNBitBinary(n,ans,temp,zero+1,ones);
        temp.pop_back();
    }
    temp.push_back('1');
    findNBitBinary(n,ans,temp,zero,ones+1);
    temp.pop_back();
}

int main(){

    vector<string> ans;
    string temp;
    
    findNBitBinary(6,ans,temp,0,0);

    for(int i=0;i<6;i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}
