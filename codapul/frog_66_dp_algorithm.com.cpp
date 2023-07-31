#include <iostream>

using namespace std;

int stonePosision[1000001] = {0,};

int jumpCnt=0;
int previousJumpLength=0;
int k=0, n=0;

int minJump(){
    int dt=0;

    previousJumpLength=0;
    jumpCnt=1;

    for (int i=0;i<n;i++){
        if ( i>0) dt = stonePosision[i] - stonePosision[i-1];
        else dt = stonePosision[i];
        
        if ( dt > k ) return -1;

        if ( dt+previousJumpLength > k ){
            jumpCnt++;
            previousJumpLength = dt;
        } else {
            previousJumpLength += dt;
        }
    }

    return jumpCnt;
}

int main(){
    int T=0;
    int result=0;

    cin >> T;

    for (int i=0;i<T;i++){
        cin >> n;

        memset(stonePosision, 0, sizeof(stonePosision));

        for (int j=0;j<n;j++){
            cin >> stonePosision[j];
        }

        cin >> k;

        result = minJump();

        cout << "Case #" << i+1 << endl << result << endl ;

    }

    return 0;
}