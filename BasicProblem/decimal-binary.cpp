#include <iostream>
using namespace std;

int main(){

    // int n;
    // cin>>n;
    // int num=0;
    // int i=0;
    // while(n>0){
    //     num = (n%2)*pow(10,i) + num;
    //     i++;
    //     n/=2;
    // }
    // cout<<num;

    int n;
    cin>>n;
    int num=0;
    int i=0;
    while(n>0){
        num+=(n%10)*pow(2,i);
        i++;
        n/=10;
    }
    cout<<num;

    return 0;
}