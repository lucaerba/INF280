#include <iostream>
#include <vector>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0
long const MAXN = 100*1000;
int occurences[3][MAXN];

long maxwin(int left, int right, int k){
    if(left >= right){
        return 1;
    }
    if(k == 0){
        //return max_occurences in left, right
        int max = 0;
        for(int i=0; i<3; i++){
            if(occurences[i][right] > max) max = occurences[i][right+1]-occurences[i][left];
        }
        return max;
    }

    int max = 0;
    for(int i=left+1; i<right; i++){
        int value = maxwin(left, i, k-1) + maxwin(i+1, right, k-1);
        if(value > max){
            max = value;
        }
        
    }
    return max;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    long N;
    int K;

    cin >> N >> K;
    char c;
    cin >> c;
    if(c == 'P'){
        occurences[0][1] = 1;
        occurences[1][1] = 0;
        occurences[2][1] = 0;
    }else if(c == 'H'){
        occurences[0][1] = 0;
        occurences[1][1] = 1;
        occurences[2][1] = 0;
    }else if(c == 'S'){
        occurences[0][1] = 0;
        occurences[1][1] = 0;
        occurences[2][1] = 1;
    }
    for(int i=2; i<N+1; i++){
        char c;
        cin >> c;
        if(c == 'P'){
            occurences[0][i] = occurences[0][i-1]+1;
            occurences[1][i] = occurences[1][i-1];
            occurences[2][i] = occurences[2][i-1];
        }else if(c == 'H'){
            occurences[0][i] = occurences[0][i-1];
            occurences[1][i] = occurences[1][i-1]+1;
            occurences[2][i] = occurences[2][i-1];
        }else if(c == 'S'){
            occurences[0][i] = occurences[0][i-1];
            occurences[1][i] = occurences[1][i-1];
            occurences[2][i] = occurences[2][i-1]+1;
        }
    }
    //print occurences
    if(DEBUG){
        for(int i=0; i<3; i++){
            for(int j=0; j<N; j++){
                cout << occurences[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << maxwin(0, N-1, K) << endl;

    return 0;
}
