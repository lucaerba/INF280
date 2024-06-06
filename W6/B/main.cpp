#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0
const int MAXS = 3000;
const long MAXT = 3*1000*1000;
char letters[MAXT];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-B.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int S;
    long T;
    map<char, int> key;

    cin >> S >> T;
    for(int i=0; i<S; i++){
        char c;
        cin >> c;
        key[c] += 1;
    }   

    if(DEBUG){
        //print the map
        for(auto it = key.begin(); it != key.end(); it++){
            cout << it->first << " " << it->second << " ";
        }
        cout << endl;
    }
    map<char, int> window;
    int nres = 0;
    
    char left;
    int n = 1;
    cin >> left;
    window[left] = 1;
    for(int i=1; i<T; i++){
        char c;
        cin >> c;
        letters[i] = c;
        if(n==S){
            window[left]-=1;
            if(window[left]==0)
                window.erase(left);
            n--;
            left = letters[i-S+1];
        }
        if(n<S){
            window[c]+=1;
            n+=1;
        }
        if(window==key) nres++;
        if(DEBUG){
            //print the map
            cout << "n " << n << endl;
            for(auto it = window.begin(); it != window.end(); it++){
                cout << it->first << " " << it->second << " ";
            }
            cout << endl;
        }
    }
    
    cout << nres << endl;
    return 0;
}
