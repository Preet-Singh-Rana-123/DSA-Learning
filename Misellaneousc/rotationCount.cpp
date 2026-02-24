#include <iostream>
using namespace std;

int rotationCount(int r,int d){
    int a,b;
    int ans = 0;
    while(r||d){
        a = r%10;
        b = d%10;
        int diff = abs(a-b);
        ans += min(diff, 10-diff);
        r/=10;
        d/=10;
    }
    return ans;
}

int main(){
    int r = 2345,d = 5432;
    cout<<"Minimum Rotation: "<<rotationCount(r,d)<<"\n";

    return 0;
}
