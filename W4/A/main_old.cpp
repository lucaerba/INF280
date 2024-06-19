#include <iostream>
#include <vector>
#include <cmath>   // <-- include cmath here
#include <algorithm>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0
const int NB_NODES_MAX = 100*1000;
int state[NB_NODES_MAX] ;
const int NOT_VISITED = -1, IN_VISIT = 1 , VISITED = 2 ;
vector<int> nxt_s[NB_NODES_MAX ];
vector<int> nxt_d[NB_NODES_MAX ];

void dfs(int node, int val) {
        state[node] = val;
        for(auto v : nxt_s[node]){
            if(state[v] == val) continue; 
            if(state[v] != NOT_VISITED){
                cout << "0" << endl;
                exit(0);
            }       
            dfs(v, val);
        }

        for(auto v : nxt_d[node]){
            if(state[v] == !val) continue;
            if(state[v] != NOT_VISITED){
                cout << "0" << endl;
                exit(0);
            }    
            dfs(v, !val);
        }   
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A_gl.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N, M;
    cin >> N >> M;
    if(DEBUG) cout << N << " " << M << endl;

    long nposs = 0;
    for(int i=0; i<M ; i++){
        char c;
        int p1, p2;
        cin >> c;
        cin >> p1 >> p2;
        p1-=1;
        p2-=1;
        if(c == 'S'){
            nxt_s[p1].push_back(p2);
            nxt_s[p2].push_back(p1);
        }else{
            nxt_d[p1].push_back(p2);
            nxt_d[p2].push_back(p1);    
        }
    }
    fill(state, state+N, NOT_VISITED);
    // if(DEBUG){
    //     for(int i=0; i<N; i++){
    //         cout << repr[i] << " ";
    //     }
    //     cout << endl;
    //     cout << nposs << endl;
    // }
    string out = "1";
    for(int i=0; i<N; i++){
        if(state[i] == NOT_VISITED){
            dfs(i, 1);
            out += "0";
        }
    }
    cout << out;
    cout << endl;
    return 0;
}
