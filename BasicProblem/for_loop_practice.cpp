#include <iostream>
using namespace std;

int main(){

    // int n,m;
    // int a = 1;
    // cin>>n;
    // cin>>m;
    // for(int i=0;i<m;i++){
    //     a*=n;
    // }
    // cout<<a;

    // int n;
    // cin>>n;
    // int a=1;
    // for(int i=1;i<=n;i++){
    //     a*=i;
    // }
    // cout<<a;

    // int n;
    // cin>>n;
    // int flag=1;
    // if(n<2){
    //     cout<<"not prime";
    //     return 0;
    // }
    // for(int i=2;i<n;i++){
    //     if(n%i==0){
    //         flag = 0;
    //         break;
    //     }
    // }
    // if(flag==1){
    //     cout<<"prime";
    // }
    // else{
    //     cout<<"not prime";
    // }

    // int n;
    // cin>>n;
    // int a,b,c;
    // a=0;
    // b=1;
    // cout<<a<<" "<<b<<" ";
    // for(int i=0;i<n-2;i++){
    //     c=a+b;
    //     a=b;
    //     b=c;
    //     cout<<c<<" ";
    // }

    // for(int i=0;i<5;i++){
        
    //     for(int j=1;j<=5;j++){
    //         char name = 'a'+j-1;
    //         cout<<name<<" ";
    //     }
    //     cout<<endl;
    // }

    // int count = 1;
    // for(int i=0;i<5;i++){
    //     for(int j=1;j<=5;j++){
    //         // cout<<count<<" ";
    //         // count++;
    //         cout<<(i*5)+j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=5;i++){
    //     for(int j=i;j>0;j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=5;i>0;i--){
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<6;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+10<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5-i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5-i;j++){
    //         cout<<"  ";
    //     }

    //     for(int j=i;j>0;j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5-i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<j<<" ";
    //     }
        
    //     for(int j=i-1;j>0;j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=5;i>0;i--){
    //     for(int j=1;j<=5-i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=2*i-1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<4;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int j=1;j<=2*(4-i);j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=4;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int j=1;j<=2*(4-i);j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    

    return 0;
}