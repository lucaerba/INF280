#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 1000;
const int MAXP = 50;

//g++ -std=c++17 main.cpp && ./a.out
//define filename = "sample-A.1.in"
#define DEBUG 0

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (DEBUG)
        freopen("sample-A.1.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //read file
    int N, P;
    double area = 0;

    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> P;
        //add area of the single polygon
        int x1, y1, x2, y2, x0, y0;
        cin >> x1 >> y1;
        x0 = x1;
        y0 = y1;
        double areap = 0;
        
        for(int j=1; j<P; j++){
            cin >> x2 >> y2;
            areap += (x2-x1)*((y2+y1)/2.0);
            x1 = x2;
            y1 = y2;
            if(DEBUG) cout << areap << endl;
        }
        areap += (x0-x1)*((y0+y1)/2.0);
        if(DEBUG) cout << areap << endl;
        
        area += abs(areap);
    }

    long areao = (long) area;
    cout << areao << endl;

    return 0;
}
