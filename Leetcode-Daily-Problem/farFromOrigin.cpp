#include <iostream>
#include <string>
using namespace std;

int furthestDistanceFromOrigin(string moves) {
    int rCount = 0;
    int lCount = 0;
    int blankCount = 0;
    for(int i=0;i<moves.size();i++){
        if(moves[i]=='L'){
            lCount++;
        }else if(moves[i]=='R'){
            rCount++;
        }else{
            blankCount++;
        }
    }
    return rCount>lCount ? rCount+blankCount-lCount : lCount+blankCount-rCount;
}

int main(){
    string moves = "_R__LL_";
    cout<<"The distance from the origin of the furthest point you can get to after n moves: "<<furthestDistanceFromOrigin(moves)<<"\n";
    return 0;
}
