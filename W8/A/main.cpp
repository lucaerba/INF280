#include <stdio.h>
#include <iostream>
#define DEBUG 0

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
int main(){
    if(DEBUG){
        freopen("sample-A.2.in", "r",stdin);
    }
    int Td, Tn;

    cin >> Td >> Tn;

    if(Td>=31 && Tn>=21){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;

}