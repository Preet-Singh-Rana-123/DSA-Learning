#include <iostream>
#include <vector>
using namespace std;

int visibleBuildings(vector<int>& arr){
    int maxHeight = arr[0];
    int count = 1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>=maxHeight){
            count++;
            maxHeight = arr[i];
        }
    }
    return count++;
}

int main(){
    vector<int> arr = {6, 2, 8, 4, 11, 13};
    cout<<"The total number of buildings that receive sunlight: "<<visibleBuildings(arr)<<"\n";
    return 0;
}
