#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//g++ main.cpp && ./a.out
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
    //7 lines with 7 values to be stored in a vector
    vector<int> v(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> v[i];
    }
    //sort the vector
    sort(v.begin(), v.end());

    //print i=3
    cout << v[3] << endl;
    

   
    return 0;
}
