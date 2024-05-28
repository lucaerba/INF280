#include <iostream>
#include <vector>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const int MAXN = 500*2+2;
int capa[MAXN][MAXN], flow[MAXN][MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
int source, target;

int dfs(int x, int max_flow) {
    if(visited[x]) return 0; // already search/ed for a flow
    if(x==target) return max_flow;// found our flow
    visited[x] = true; // stop visiting x
    for(int n: adj[x]) // mixes adjacency lists with matrix
        if(flow[x][n] < capa[x][n]) { // residual
            const int sub_flow = dfs(n, min(max_flow,capa[x][n]-flow[x][n]));
            if(sub_flow > 0) {
                flow[x][n]+= sub_flow;
                flow[n][x]-= sub_flow;
                return sub_flow;
            }
        }
    return 0; // haven't found a flow
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-C__.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N, K;

    cin >> N >> K;

    if(DEBUG) cout << N << " " << K << endl;

    source = 0;
    target = 2 * N + 1;

    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        adj[source].push_back(r);
        adj[r].push_back(source);
        capa[source][r] = 1;

        adj[r].push_back(N + c);
        adj[N + c].push_back(r);
        capa[r][N + c] = 1;

        adj[N + c].push_back(target);
        adj[target].push_back(N + c);
        capa[N + c][target] = 1;
    }
    
    //vertex cover with minimal path -> maximum matching 
    int totalFlow = 0, curFlow = 1 ;
    while(curFlow > 0) {
        fill(visited,visited+MAXN,false) ;
        curFlow = dfs(source,INT32_MAX) ;
        totalFlow += curFlow ;
    }

    cout << totalFlow << endl;
    return 0;
}
