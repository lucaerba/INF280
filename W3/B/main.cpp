#include <iostream>
#include <vector>
#include <cmath>   // <-- include cmath here

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const int NB_NODES_MAX = 200;
vector<  int  > nxt[NB_NODES_MAX];

int state[NB_NODES_MAX] ;
const int NOT_VISITED = 0, IN_VISIT = 1 , VISITED = 2 ;
int ncow = 0;
void dfs(int node) {
    if(state[node] == NOT_VISITED) {
        state[node] = IN_VISIT ;
        for(auto v : nxt[node])
            dfs(v);
        state[node] = VISITED ;
        ncow++; //added
    }
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
    

    //read and create graph calculating edges if distance <= power
    //bidirection for visit in both direction
    vector<pair<pair<int,int>,int>> cows;
    for(int i=0; i<N; i++){
        int x, y, p;
        cin >> x >> y >> p;
        cows.push_back({make_pair(x,y),p});
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j){
                if(pow(cows[i].first.first-cows[j].first.first, 2)+
                    pow(cows[i].first.second-cows[j].first.second, 2)
                    <=pow(cows[i].second,2))
                    nxt[i].push_back(j);
            }
        }
    }

    //dfs to look for the maximum vistable area
    int ncowmax = 0;
    for(int i=0; i<N; i++){
        ncow = 0;
        fill(state, state+N, NOT_VISITED);
        dfs(i);
        if(ncow > ncowmax) ncowmax = ncow;
    }
    cout << ncowmax << endl;
   
    return 0;
}
