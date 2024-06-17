#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAXN = 20;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

const pair<int, int> N = {0, 1};
const pair<int, int> S = {0, -1};
const pair<int, int> E = {-1, 0};
const pair<int, int> W = {1, 0}; 
const map<char, pair<int,int>> directions = {    
    {'N', N},
    {'S', S},
    {'E', E},
    {'W', W}
};
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        char c0, c1;
        string s;
        double area = 0;
        cin >> s;
        pair<int, int> p0 = {0, 0};
        
        for(int i=0; i<s.size()-1; i++){
            pair<int, int> p1 = p0;
            p1.first += directions.at(s[i]).first;
            p1.second += directions.at(s[i]).second;

            area += p0.first * p1.second - p1.first * p0.second;
            p0 = p1;
            
            if(DEBUG) cout << "area: " << area << endl;
        }
        if(area > 0) cout << "CW" << endl;
        else cout << "CCW" << endl; 

    }
    return 0;
}
