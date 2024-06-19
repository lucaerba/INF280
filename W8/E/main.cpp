#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#define DEBUG 0

using namespace std;

// Function to convert a 3-digit sequence to a number in a given base
int convertToDecimal(const string& sequence, int base) {
    return (sequence[0] - '0') * base * base + (sequence[1] - '0') * base + (sequence[2] - '0');
}

int main() {
    if(DEBUG){
        freopen("sample-E.1.in", "r", stdin);

    }  
    int K;
    cin >> K;

    vector<pair<string, string>> cases(K);
    for (int i = 0; i < K; ++i) {
        cin >> cases[i].first >> cases[i].second;
    }
    
    for (const auto& [seqX, seqY] : cases) {
        unordered_map<int, int> valueToBaseX;
        
        // Store the values for all possible bases for seqX
        for (int X = 10; X <= 15000; ++X) {
            int value = convertToDecimal(seqX, X);
            valueToBaseX[value] = X;
        }
        
        // Find the common value in the second sequence's bases
        bool found = false;
        for (int Y = 10; Y <= 15000 && !found; ++Y) {
            int value = convertToDecimal(seqY, Y);
            if (valueToBaseX.find(value) != valueToBaseX.end()) {
                cout << valueToBaseX[value] << " " << Y << endl;
                found = true;
            }
        }
    }

    return 0;
}
