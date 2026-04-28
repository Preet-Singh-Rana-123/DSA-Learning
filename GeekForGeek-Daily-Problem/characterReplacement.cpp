#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestSubstr(string& s, int k){
    vector<int> freq(26,0);
    int maxFreq = 0;
    int ans = 0;
    int left = 0;

    for(int i=0;i<s.size();i++){
        freq[s[i]-'A']++;

        maxFreq = max(maxFreq,freq[s[i]-'A']);

        while((i-left+1) - maxFreq > k){
            freq[s[left]]--;
            left++;
        }

        ans = max(ans,(i-left+1));
    }
    return ans;
}

int main(){
    string s = "ADBD";
    int k =1;
    cout<<"The longest substring that can be transformed into a string with all identical characters after performing at most k such operations: "<<longestSubstr(s,k)<<"\n";
    return 0;
}
