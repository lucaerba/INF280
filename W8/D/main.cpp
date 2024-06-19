#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define DEBUG 0
using namespace std;

const int MAXN = 500;


int dp[MAXN][MAXN];
vector<pair<int, int>> points;

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    // Redirecting input for debugging purposes
    if( DEBUG)
        freopen("sample-D.1.in", "r", stdin);
        

    int N, K;
    cin >> N >> K;
    if(DEBUG)
        cout << N << " " << K << endl;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    // Initialize DP table
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp[i][j] = INT32_MAX;
        }
    }

    dp[0][0] = 0;  // Starting point

    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= K; k++) {
            if (dp[i][k] == INT32_MAX)
                continue;

            for (int j = i + 1; j < N && j <= i + 1 + K; j++) {
                int new_k = k + (j - i - 1);
                if (new_k <= K) {
                    dp[j][new_k] = min(dp[j][new_k], // distance to new point removing the i distance 
                                dp[i][k] + dist(points[i], points[j])); // distance to new point adding the i distance
                }
            }
        }
    }
    if(DEBUG) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= K; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    int ans = INT32_MAX;
    for (int k = 0; k <= K; k++) {
        ans = min(ans, dp[N - 1][k]);
    }

    cout << ans << endl;

    return 0;
}
