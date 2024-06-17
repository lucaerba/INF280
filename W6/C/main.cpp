#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1
//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"

const int MAXXY = 1000;
int map[MAXXY+1][MAXXY+1];    

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    // Read input
    long N, K;
    cin >> N >> K;
    int max_x = 0, max_y = 0;
    for(int i=0; i<N; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Use a 2D difference array to reduce the number of updates
        map[x1][y1]++;
        map[x2][y1]--;
        map[x1][y2]--;
        map[x2][y2]++;
        if(x2 > max_x) max_x = x2;
        if(y2 > max_y) max_y = y2;
    }
    
    // Apply prefix sums to compute the final values in the map !! prefix sums on 2D array
    for(int i=0; i<=max_x; i++){
        for(int j=0; j<=max_y; j++){
            if(i > 0) map[i][j] += map[i-1][j];
            if(j > 0) map[i][j] += map[i][j-1];
            if(i > 0 && j > 0) map[i][j] -= map[i-1][j-1];
        }
        //print the map
        if(DEBUG){
            for(int i=0; i<=max_x; i++){
                for(int j=0; j<=max_y; j++){
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    //print the map
    if(DEBUG){
        for(int i=0; i<=max_x; i++){
            for(int j=0; j<=max_y; j++){
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Count the cells with the exact value K
    int res = 0;
    for(int i=0; i<MAXXY; i++){
        for(int j=0; j<MAXXY; j++){
            if(map[i][j] == K) res++;
        }
    }

    cout << res << endl;
    return 0;
}
