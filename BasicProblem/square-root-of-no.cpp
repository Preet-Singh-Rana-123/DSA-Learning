#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int i=1;
    while(true){
        if(i*i>n){
            break;
        }
        i++;
    }
    cout<<i-1;

    return 0;
}