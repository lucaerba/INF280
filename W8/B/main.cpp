#include <stdio.h>
#include <iostream>
#define DEBUG 0

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
int main(){
    if(DEBUG){
        freopen("sample-B.1.in", "r",stdin);
    }
    
    int D, H, M;

    cin >> D >> H >> M;

    long timestamp_start = 11 + 11*60 + 11*24*60;
    long timestamp_end = M + H*60 + D*24*60;

    if(timestamp_end < timestamp_start) {
        cout << "-1" << endl;
        return 0;
    }

    cout << timestamp_end - timestamp_start << endl;

    return 0;

}