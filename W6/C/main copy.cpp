#include <iostream>
#include <vector>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0
const int MAXXY = 1000;
int map[MAXXY][MAXXY];    

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    long N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //fill the map
        for(int i=x1; i<x2; i++){  //problema... 
            for(int j=y1; j<y2; j++){
                map[i][j] ++;
            }
        }
    }
    
    int res = 0;
    for(int i=0; i<MAXXY; i++){
        for(int j=0; j<MAXXY; j++){
            if(map[i][j] == K) res++;
        }
    }

    cout << res << endl;
    return 0;
}
