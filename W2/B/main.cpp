#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

//g++ main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    string line;
    unordered_set<string> values;

    while(getline(cin, line)){
        //split the line
        int i = 0;
        while (line[i] != ' ')
        {
            i++;
        }
        i++;

        //read the monument
        string monument;
        while (i < line.size()){
            monument += line[i++];
        }
        //cout << monument;
        values.insert(monument);
    }
    cout << values.size() << endl;

    //read file
   
    return 0;
}
