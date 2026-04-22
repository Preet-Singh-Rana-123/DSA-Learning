#include <iostream>
#include <vector>
using namespace std;

vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> ans;
    vector<int> prefixSum(arr.size(),0);
    prefixSum[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }

    for(int i=0;i<queries.size();i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int sum = 0;
        int len = r-l+1;
        if(l==0){
            sum = prefixSum[r];
        }else{
            sum = prefixSum[r]-prefixSum[l-1];
        }
        ans.push_back(sum/len);
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{0,2},{1,3},{0,4}};
    vector<int> ans = findMean(arr,queries);
    for(int n : ans){
        cout<<n<<" ";
    }
    cout<<"\n";
    return 0;
}
