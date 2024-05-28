#include <iostream>
#include <vector>
#include <cmath>   // <-- include cmath here
#include <algorithm>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int repr[25001] ; // initialized to -1
int find(int x) {
    if(repr[x] < 0) return x;
    return repr[x]=find(repr[x]); // path compression
}
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) { return false; }
    if(repr[a] > repr[b]) { swap(a,b); } // size
    repr[a] += repr[b] ;
    repr[b] = a;
    return true;
} 
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N;
    cin >> N;

    vector<pair<int, int>> cows;

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        if(DEBUG) cout << x << " " << y << endl;
        cows.push_back({x, y});
    }

    vector<pair<long, int>> distances[N];
    vector<pair<int, pair<int,int> > > edges;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j){
                long distancex = cows[i].first-cows[j].first;
                long distancey = cows[i].second-cows[j].second;
                edges.push_back({distancex*distancex + distancey*distancey, {i, j}});
            }
        }
    }
    // ...
    sort(edges.begin(),edges.end());
    fill(repr, repr+N, -1);
    long long weight_mst = 0;
    long long weight_max = 0;

    //minimum spanning tree
    for(auto [w,p] : edges)
        if(unite(p.first,p.second)){
            weight_mst += w;
            if(w>weight_max) weight_max = w;
        }


    cout << weight_max << endl;
    return 0;
}
