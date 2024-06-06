#include <iostream>
#include <vector>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const int MAXN = 1000;
const int MAXM = 2000;
vector<int> roads[MAXN];
int dp[MAXN][MAXM];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> cities(N);
    for(int i=0; i<N; i++){
        cin >> cities[i];
    }

    for(int i=0; i<M; i++){
        int u, v;
        u--; v--;
        cin >> u >> v;
        roads[u].push_back({v});
        roads[v].push_back({u});
    }
    

    return 0;
}
