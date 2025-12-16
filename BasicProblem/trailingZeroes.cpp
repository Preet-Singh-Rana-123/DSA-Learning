#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a=0;
    while(n>0){
        a+=(n/5);
        n/=5;
    }
    cout<<a;

    return 0;
}