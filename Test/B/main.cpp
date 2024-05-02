#include <iostream>
#include <vector>

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

    //read file
    //read n, then n numbers
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int avg = sum / n;

    int nmoved = 0; 
    for (int i = 0; i < n; i++)
    {
        if (a[i] < avg)
        {
            nmoved += avg - a[i];
        }
    }

    cout << nmoved << endl;
    return 0;
}
