#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0
using namespace std;

const long MAXN = 100000;
const long MAXK = 20;
int occurrences[3][MAXN + 1];
long memo[MAXN + 1][3][MAXK + 1];
bool visited[MAXN + 1][3][MAXK + 1];


// Function to calculate the wins for a given gesture range
int wins(int left, int right, int gesture) {
    return occurrences[gesture][right] - occurrences[gesture][left - 1];
}

// Recursive function with memoization to calculate the maximum wins
long maxwin(int N, int gesture, int k) {
    if (N == 0) return 0;
    if (visited[N][gesture][k]) return memo[N][gesture][k];

    long result = wins(1, N, gesture);

    if (k > 0) {
        for (int new_gesture = 0; new_gesture < 3; ++new_gesture) {
            if (new_gesture != gesture) {
                for (int i = 1; i <= N; ++i) {
                    result = max(result, maxwin(i, new_gesture, k - 1) + wins(i + 1, N, gesture));
                }
            }
        }
    }

    visited[N][gesture][k] = true;
    memo[N][gesture][k] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (DEBUG)
        freopen("sample-B.1.in", "r", stdin);
   
    int N, K;
    cin >> N >> K;

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
    //print occurrences
    if(DEBUG){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j <= N; ++j) {
                cout << occurrences[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    long max_wins = 0;
    for (int gesture = 0; gesture < 3; ++gesture) {
        max_wins = max(max_wins, maxwin(N, gesture, K));
    }

    cout << max_wins << endl;

    return 0;
}
