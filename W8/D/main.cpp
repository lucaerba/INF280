#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG 1

using namespace std;
const int MAXN=500;
const int MAXD=2001;
int distances[MAXN][MAXN];

//g++ -std=c++17 main.cpp && ./a.out
int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first)+abs(p1.second - p2.second);
}
int main(){
    if(DEBUG){
        freopen("sample-D.1.in", "r",stdin);
    }
    
    int N, K;

    cin >> N >> K;
    vector<pair<pair<int,int>, pair<int, int>>> points;
    int x,y;
    cin >> x >> y;
    points.push_back({{x,y}, {0, 0}});
    for(int i=1; i<N; i++){
        int x,y;
        cin >> x >> y;
        points.push_back({{x,y}, {distance({x,y}, points.at(i-1).first), i}});
        if(DEBUG) cout << x <<" " << y <<endl;
    }


    //look for most distant points
    
    vector<pair<pair<int,int>, pair<int, int>>> points_sorted = points;
    sort(points_sorted.begin(), points_sorted.end(), 
        [](const pair<pair<int,int>, pair<int, int>>& p1,  const pair<pair<int,int>, pair<int, int>>& p2){
            return p1.second.first - p2.second.first;
        });
    
    //try to remove K points
    for(int i=0; i<K; i++){
        if(DEBUG){
            cout << points_sorted.at(i).first.first << " " <<points_sorted.at(i).first.second << " " << points_sorted.at(i).second.first << endl;
        }
        points.erase(points_sorted.begin()+points_sorted.at(i).second.second);
    }
    int nres = points.size();
    long res =0;
    for(int i=0; i<nres; i++){
        if(i+1 < nres){
            res += distance(points.at(i).first, points.at(i+1).first); 
        }
    }

    cout << res << endl;

    
    return 0;

}