#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

const int NB_NODES_MAX = 2000;
vector<pair<int, pair<int, int> > > nxt[NB_NODES_MAX];

void readGraph(int n, int m) {
    for(int i = 0 ; i < m ; i++) {
        int a,b,c,f ;
        scanf("%d %d %d %d",&a,&b,&c, &f);
        nxt[a-1].push_back({b-1, make_pair(c, f)});
        nxt[b-1].push_back({a-1, make_pair(c, f)}); // if undirected
    }
}

int main(int argc, char const *argv[])
{
    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int n, m;

    cin >> n >> m;

    readGraph(n, m);
    long long max_result = 0;
    for(int i=1; i<=1000; i+=1){
        int tot_cost = 0;

        long long dist[NB_NODES_MAX];
        //...
        fill(dist, dist+NB_NODES_MAX, INT32_MAX);
        set<pair<long long,int>> p_queue; // (weight, node)
        int start_node = 0;
        p_queue.insert(make_pair(0,start_node));
        dist[start_node] = 0;

        while(!p_queue.empty()) {
            auto [node_dist, node] = *p_queue.begin() ; // c++17
            p_queue.erase(p_queue.begin());
                for(auto v : nxt[node])
                    if( node_dist + v.second.first < dist[v.first] &&(v.second.second >= i) ) {
                        p_queue.erase(make_pair(dist[v.first],v.first));
                        dist[v.first] = node_dist + v.second.first;
                        p_queue.insert(make_pair(dist[v.first],v.first));
                    }
        }
        tot_cost = dist[n-1];
        int min_flow = i;
        
        long long result = 1000 * 1000 * min_flow/tot_cost;
        if (result > max_result) max_result = result;
        
    }
    cout << max_result << endl;
    return 0;
}
