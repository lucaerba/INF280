#include <iostream>
#include <vector>
#include <set>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int main(int argc, char const *argv[])
{
    if (DEBUG)
        freopen("sample-D_.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file 
    int n;
    cin >> n;

    string road;
    cin >> road;

    for(int i=1; i<n; i++){
        set<string> combinations;
        bool OK = true;
        for(int j=0; (j+i)<=n; j++){
            string s;
            for(int k=0; k<i; k++){
                s += road[j+k];
            }
            if(DEBUG)
                cout << s << endl;
            if(combinations.find(s) != combinations.end()){
                OK = false;
                continue;
            }
            combinations.insert(s);
        }
        if(OK){
            cout << i << endl;
            return 0;
        }
    }
   
    return 0;
}
