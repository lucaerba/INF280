#include <iostream>
#include <vector>
#include <set>

using namespace std;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0
#define MAXN 20000
#define MAXC 10
long N;
int C;
int chords[MAXN+1];
int schords[MAXC+1];
int subchords[MAXC+1];
vector<int> results;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    cin >> N;

    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        chords[i] = c;
    }
    
    cin >> C;
    int min = INT16_MAX;

    set<int> subchordsSet;
    set<int> checkSet;

    for(int i=0; i<C; i++){
        int c;
        cin >> c;
        schords[i] = c;
        if(c<min) min = c;
    }
    for(int i=0; i<C; i++){
        schords[i] -= min;
        checkSet.insert(schords[i]);
    }

    if(DEBUG){
        for(auto x: checkSet){
            cout << x << " ";
        }
        cout << endl;
    }

    for(int i=0; i<N-C+1; i++){
        //add the chords to the set and check
        min = INT16_MAX;
        subchordsSet.clear();
        for(int j=0; j<C; j++ ){
            subchords[j] = chords[i+j];
            if(chords[i+j] < min) min = chords[i+j];
        }
        for(int j=0; j<C; j++ ){
            subchords[j] -= min;
            subchordsSet.insert(subchords[j]);
        }
        if(DEBUG){
            for(auto x: subchordsSet){
                cout << x << " ";
            }
            cout << endl;
        }
        if(checkSet == subchordsSet){
            results.push_back(i);
        }

    }

    cout << results.size() << endl;
    for(auto x: results) cout << x+1 << endl;

    return 0;
}
