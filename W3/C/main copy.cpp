#include <iostream>
#include <vector>
#include <set>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1

int B, E, P, N, M;
const int NB_NODES_MAX = 40000;
const int MAX_DISTANCE = 40000;
vector<pair<int,  int > > nxt[NB_NODES_MAX];
vector<int> nodes_at[MAX_DISTANCE];

int dist[NB_NODES_MAX];

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

    int res_min = INT32_MAX;
    for(int i=1; i<N-1; i++){
        int res = 0;

        bfs(0, i, M);
        res += dist[i]*B;
        
        bfs(1, i, M);
        res += dist[i]*E;
        
        bfs(i, N-1, M);
        res += dist[N-1]*P;
        if(res < res_min) res_min = res;
    }
   
    cout << res_min << endl;
    return 0;
}
