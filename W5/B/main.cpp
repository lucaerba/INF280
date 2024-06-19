#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1
using namespace std;

const long MAXN = 100000;
const long MAXK = 20;
int occurrences[3][MAXN + 1];
long dp[MAXN + 1][3][MAXK + 1];

// Function to calculate the wins for a given gesture range
int wins(int left, int right, int gesture) {
    return occurrences[gesture][right] - occurrences[gesture][left - 1];
}

int main() {

    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
   
    int N, K;
    cin >> N >> K;

    // Initialize the occurrences array
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            occurrences[j][i] = occurrences[j][i - 1];
        }
        char c;
        cin >> c;
        if (c == 'P') occurrences[0][i]++;
        else if (c == 'H') occurrences[1][i]++;
        else if (c == 'S') occurrences[2][i]++;
    }

    // Fill the DP table
    for (int i = 1; i <= N; ++i) { // i is the number of gestures in the game
        for (int j = 0; j < 3; ++j) { // j is the last gesture
            dp[i][j][0] = dp[i - 1][j][0] + wins(i, i, j);
            for (int k = 1; k <= K; ++k) { // k is the number of switches
                dp[i][j][k] = dp[i - 1][j][k] + wins(i, i, j);
                for (int l = 0; l < 3; ++l) { // l is the previous gesture
                    if (l != j) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][k - 1] + wins(i, i, j));
                    }
                }
            }
        }
    }

    // Get the maximum wins with up to K switches
    long max_wins = 0;
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k <= K; ++k) {
            max_wins = max(max_wins, dp[N][j][k]);
        }
    }

    // Output the result
    cout << max_wins << endl;
    return 0;
}