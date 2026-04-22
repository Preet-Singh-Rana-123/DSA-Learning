#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary){
    vector<string> ans;
    for(auto q : queries){
        for(auto s : dictionary){
            int diff = 0;
            for(int i=0;i<q.size();i++){
                if(s[i]!=q[i]){
                    diff++;
                }
                if(diff>2){
                    break;
                }
            }
            if(diff<=2){
                ans.push_back(q);
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<string> queries = {"word","note","ants","wood"};
    vector<string> dictionary = {"wood","joke","moat"};
    vector<string> ans = twoEditWords(queries,dictionary);
    for(auto s : ans){
        cout<<s<<" ";
    }
    cout<<"\n";
    return 0;
}
