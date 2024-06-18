#include <stdio.h>
#include <iostream>
#define DEBUG 0

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
int main(){
    if(DEBUG){
        freopen("sample-C.1.in", "r",stdin);
    }
    
    long N;
    cin >> N;

    int max = 0;
    int max_l = 0;
    if(DEBUG) cout << N << endl;

    for(int i=0; i<N; i++){
        int Td, Tn;
        cin >> Td >> Tn;

        if(DEBUG) cout << Td << " "<<Tn << endl;

        if(Td>=31 && Tn>=21){
            max++;
        }else{
            if(DEBUG) cout << max << " "<<max_l << endl;
            max_l = max>max_l?max:max_l;
            max=0;
        }
    }
    max_l = max>max_l?max:max_l;
    cout << max_l << endl;
    
    
    return 0;

}