#include <iostream>
#include <vector>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1
const int MAXN = 500;
long tot = 0;
long solution[MAXN];

long rec(vector<long> subset, int level){
    if(subset.size() == 1){
        if(DEBUG){
            cout << "end" << subset[0] << endl;
        }
        return subset[0];  
    }
    
    long N = subset.size();
    long min_val = INT32_MAX;
    long tot = 0;
    for(int i=1; i<N; i++){
        vector<long> subset_l(subset.begin(), subset.begin()+i);
        vector<long> subset_r(subset.begin()+i, subset.end());
 
        long val = rec(subset_l, level-1) + rec(subset_r, level-1) ;
        min_val = min(min_val, val);
    }
    if(min_val < solution[level-1]) solution[level-1] = min_val;
    
    return min_val;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("gl.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N;
    cin >> N;
    vector<long> lis;
    for(int i=0; i<N; i++){
        int li;
        cin >> li;
        lis.push_back(li);
    }
    fill(solution, solution+N, INT32_MAX);
    long ret = rec(lis, N);
    for(int i=1; i<N; i++){
        if(DEBUG){
            cout << solution[i] << " " ;
        }
        tot += solution[i];
    }
    if(DEBUG) cout << endl;
    cout << ret << endl;
    
    return 0;
}
