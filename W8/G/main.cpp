#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define DEBUG 0

struct Cow {
    long x, y;
    char breed;
};

const long MAX_C = 1000;

int main() {
    if(DEBUG) {
        freopen("sample-G.1.in", "r", stdin);
    }
    int N;
    cin >> N;

    vector<Cow> holsteins, guernseys;
    for (int i = 0; i < N; ++i) {
        Cow cow;
        cin >> cow.x >> cow.y >> cow.breed;
        if (cow.breed == 'H') {
            holsteins.push_back(cow);
        } else {
            guernseys.push_back(cow);
        }
    }

    int maxHolsteins = 0;
    long minArea = MAX_C * MAX_C;

    int H = holsteins.size();

    for (int i = 0; i < H; ++i) {
        for (int j = i; j < H; ++j) {  // Include j = i to consider rectangles with zero width/height
            long x1 = min(holsteins[i].x, holsteins[j].x);
            long x2 = max(holsteins[i].x, holsteins[j].x);
            long y1 = min(holsteins[i].y, holsteins[j].y);
            long y2 = max(holsteins[i].y, holsteins[j].y);

            int count = 0;
            bool valid = true;

            for (const Cow& cow : holsteins) {
                if (cow.x >= x1 && cow.x <= x2 && cow.y >= y1 && cow.y <= y2) {
                    ++count;
                }
            }

            for (const Cow& cow : guernseys) {
                if (cow.x >= x1 && cow.x <= x2 && cow.y >= y1 && cow.y <= y2) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                if (count > maxHolsteins) {
                    maxHolsteins = count;
                    minArea = (x2 - x1) * (y2 - y1);
                } else if (count == maxHolsteins) {
                    long area = (x2 - x1) * (y2 - y1);
                    if (area < minArea) {
                        minArea = area;
                    }
                }
            }
        }
    }

    cout << maxHolsteins << endl;
    cout << minArea << endl;

    return 0;
}
