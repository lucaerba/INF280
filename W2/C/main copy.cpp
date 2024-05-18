#include <iostream>
#include <vector>
#include <map>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 1

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-C.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int n, m;

    cin >> n >> m;
    map <pair<int,int>, pair<int,int>> pipes;
    int f_min = -1;

    for(int i=0; i<m; i++){
        int a,b, c,f;
        cin >> a >> b >> c >> f;
        pair<int, int> key;
        if(a<b)
            key = make_pair(a, b);
        else 
            key = make_pair(b, a);
        
        if(pipes.find(key) == pipes.end()){
                pipes[key] = make_pair(c, f);
        }else{
            int c_old, f_old;
            c_old = pipes[key].first;
            f_old = pipes[key].second;
            if(f/c > f_old/c_old){
                pipes[key] = make_pair(c, f);
            }
        }
    }

    int tot_cost = 0;

    for(auto & x: pipes){
        tot_cost += x.second.first;
        if(f_min == -1 || x.second.second < f_max) f_min = x.second.second;
    }
    if(DEBUG)
        cout << tot_cost << " "<< f_min << endl;
    int result = 1000 * 1000 * f_min/tot_cost;

    cout << result << endl;
    return 0;
}
