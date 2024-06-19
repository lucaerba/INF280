#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define DEBUG 1
using namespace std;

const int MAXN = 1000;
const int MAXDAYS = 2000; // Setting this to 2*N to cover practical limits
const int INF = -1e9; // A large negative number to represent impossible states

int N, M, C;
int moonies[MAXN + 1];
vector<int> adj[MAXN + 1];
int dp[MAXN + 1][MAXDAYS + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (DEBUG)
        freopen("sample-C.1.in", "r", stdin);
    
    cin >> N >> M >> C;
    for (int i = 1; i <= N; ++i) {
        cin >> moonies[i];
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(dp, -INF, sizeof(dp));
    dp[1][0] = 0;

    int maxDays = 0;
    for (int t = 0; t < MAXDAYS; ++t) {
        bool updated = false;
        for (int i = 1; i <= N; ++i) {
            if (dp[i][t] != INF) {
                for (int j : adj[i]) {
                    if (dp[j][t + 1] < dp[i][t] + moonies[j]) {
                        dp[j][t + 1] = dp[i][t] + moonies[j];
                        updated = true;
                    }
                }
            }
        }
        if (!updated) {
            maxDays = t;
            break;
        }
    }

    int maxEarnings = 0;
    //considering we have to go back to the moon base
    for (int i = 1; i <= N; ++i) {
        if (i == 1) { // Assuming node 1 is the moon base
            maxEarnings = max(maxEarnings, dp[i][maxDays] - C * maxDays * maxDays);
        } else {
            maxEarnings = max(maxEarnings, dp[i][maxDays]);
        }
    }

    cout << maxEarnings << endl;

    return 0;
}