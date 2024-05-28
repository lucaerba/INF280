#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

long B, E, P, N, M;
const int NB_NODES_MAX = 40000;
const int MAX_DISTANCE = 40000;
vector<pair<int,  int > > nxt[NB_NODES_MAX];
vector<int> nodes_at[MAX_DISTANCE];

long dist[NB_NODES_MAX];

void bfs(int start, int end, int max_distance) {
    
    fill(dist,dist+NB_NODES_MAX,INT32_MAX);
    nodes_at[0] = {start} ;
    dist[start] = 0 ;

    for(int cur_dist = 0 ; cur_dist < max_distance ; cur_dist++ )
        for(size_t id = 0 ; id < nodes_at[cur_dist].size() ; id++) {
            const int node = nodes_at[cur_dist][id] ;
            if(dist[node] == cur_dist)
                for(auto [neigh,len] : nxt[node]){ //neighbours
                    if(dist[neigh] > cur_dist+len) {
                        dist[neigh] = cur_dist+len ;
                        nodes_at[dist[neigh]].push_back(neigh);
                    }
                }
        }
   
}
int main(int argc, char const *argv[])
{
    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    cin >> B >> E >> P >> N >> M;
    
    if(DEBUG)
        cout << B << " " << E << " " << P << " " << N << " " << M << endl;

    for(int i=0; i<M; i++){
        long x, y;
        cin >> x >> y;
        x-=1;
        y-=1;
        nxt[x].push_back({y, 1});
        nxt[y].push_back({x, 1});
    }
    
    bfs(0, N-1, M);
    long dist0[N];
    for(int i=0; i<N; i++){
        dist0[i] = dist[i];
    }
    if (DEBUG){
        for(int i=0; i<N; i++) {
            cout << dist[i] << endl;
        }
        cout << endl;
    }
    bfs(1, N-1, M);
    if (DEBUG){
        for(int i=0; i<N; i++) {
            cout << dist[i] << endl;
        }
        cout << endl;
    }
    long dist1[N];
    for(int i=0; i<N; i++){
        dist1[i] = dist[i];
    }
    
    bfs(N-1, 0, M);
    long distN[N];
    for(int i=0; i<N; i++){
        distN[i] = dist[i];
    }
    if (DEBUG){
        for(int i=0; i<N; i++) {
            cout << dist[i] << endl;
        }
        cout << endl;
    }
    long long res_min = LONG_MAX;
    
    for(int i=0; i<N; i++){
        long long res = 0;
        res += dist0[i]*B;
        
        res += dist1[i]*E;
        
        res += distN[i]*P;

        if(DEBUG) cout << i << " " << res << endl;

        if(res < res_min)
            res_min = res;
    }
    
    cout << res_min << endl;
    return 0;
}
