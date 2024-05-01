#include <iostream>
#include <vector>

using namespace std;

//define filename = "sample-A.1.in"
int N, W, L = 0;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("sample-B.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    //4 W
    // 7 N 
    // 2 3 wi li
    // 1 4
    // 1 2
    // 1 2
    // 2 2
    // 2 2
    // 2 1
    //read W,N, read all the cake pieces dimensions and calculate the total area, then divide by W
    // got the L, print it
    cin >> W >> N;
    int total_area = 0;
    for (int i = 0; i < N; i++)
    {
        int w, l;
        cin >> w >> l;
        total_area += w * l;
    }
    L = total_area / W;
    cout << L << endl;
    return 0;
}
