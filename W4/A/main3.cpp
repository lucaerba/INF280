#include <iostream>
#include <vector>
#include <cmath>   // <-- include cmath here
#include <algorithm>
#include <set>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const int NB_NODES_MAX = 100*1000;
int state[NB_NODES_MAX] ;
const int NOT_VISITED = 0, IN_VISIT = 1 , VISITED = 2 ;

vector<pair<int,int>> nxt[NB_NODES_MAX ];
int reprDiff[NB_NODES_MAX] ; // initialized to -1
int reprSame[NB_NODES_MAX] ; // initialized to -1

int find(int x, int repr[]) {
    if(repr[x] < 0) return x;
    return repr[x]=find(repr[x], repr); // path compression
}
bool unite(int a, int b, int repr[]) {
    a = find(a, repr);
    b = find(b, repr);
    if(a==b) { return false; }
    if(repr[a] > repr[b]) { swap(a,b); } // size
    repr[a] += repr[b] ;
    repr[b] = a;
    return true;
} 
void dfs(int node) {
    if(state[node] == NOT_VISITED) {
        state[node] = IN_VISIT ;
        for(auto v : nxt[node])
            dfs(v.second);
        state[node] = VISITED ;
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A_.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N, M;
    cin >> N >> M;
    if(DEBUG) cout << N << " " << M << endl;

    long nposs = 0;

    fill(reprDiff, reprDiff+NB_NODES_MAX, -1);
    fill(reprSame, reprSame+NB_NODES_MAX, -1);
    
    for(int i=0; i<M ; i++){
        char c;
        int p1, p2;
        cin >> c;
        cin >> p1 >> p2;
        p1-=1;
        p2-=1;
        if(c == 'S'){
            if(find(p1, reprDiff) == find(p2, reprDiff)) {
                cout << "0\n";
                return 0;
            }
            unite(p1, p2, reprSame);
        } else {
            if(find(p1, reprSame) == find(p2, reprSame)) {
                cout << "0\n";
                return 0;
            }
            unite(p1, p2, reprDiff);
        }
        nxt[p1].push_back({1,p2});
        nxt[p2].push_back({1,p1});
    }
    // if(DEBUG){
    //     for(int i=0; i<N; i++){
    //         cout << repr[i] << " ";
    //     }
    //     cout << endl;
    //     cout << nposs << endl;
    // }
    for(int i=0; i<N; i++){
        if(state[i] == NOT_VISITED){
            dfs(i);
            nposs++;
        }
    }
    cout << "1";
    for(int i=0; i<nposs; i++) cout << "0";
    cout << endl;
    return 0;
}
