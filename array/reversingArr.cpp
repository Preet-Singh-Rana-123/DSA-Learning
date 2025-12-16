#include <iostream>
using namespace std;

int main(){

    int arr[7] = {1,2,3,4,5,6,7};
    int i=0,j=7-1,temp;
    while(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}