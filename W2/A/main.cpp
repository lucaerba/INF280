#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

//g++ -std=c++11 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A.2.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    map<string, int> values;
    int n;

    cin >> n;
    
    for(int i=0; i<n; i++){
        string key;
        cin >> key;
        if(values.find(key) == values.end()){
            values[key] = 1;
        }else{
            values[key] ++;
        }
    }

    bool feasible = true;
    int max = 0;
    string max_a = "NONE";
    bool first = true;
    for(auto & x: values){
        if(first || x.second>max){
            max = x.second;
            first = false;
            max_a = x.first;
        }
    }

    if(max > (n-max)){
        cout << max_a << endl;
    }else{
        cout << "NONE" << endl;
    }

    return 0;
}
