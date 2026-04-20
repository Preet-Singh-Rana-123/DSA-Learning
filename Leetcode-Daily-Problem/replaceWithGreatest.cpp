#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr){
    int n = arr.size();
    int maxNum = -1;
    for(int i=n-1;i>=0;i--){
        int current = arr[i];
        arr[i] = maxNum;
        maxNum = max(maxNum,current);
    }
    return arr;
}

int main(){
    vector<int> arr = {17,18,5,4,6,1};
    replaceElements(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
