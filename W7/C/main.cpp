#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
#define DEBUG 1

#define pii pair<int, int>

bool turnRight(pii a, pii b, pii c) {
    // Cross product to determine if the turn is right
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first) < 0;
}

vector<pii> convexHull(vector<pii> in) {
    if (in.size() <= 1) return in;
    sort(in.begin(), in.end());
    vector<pii> hull;

    // Lower hull
    for (pii p : in) {
        while (hull.size() >= 2 && !turnRight(hull[hull.size() - 2], hull[hull.size() - 1], p))
            hull.pop_back();
        hull.push_back(p);
    }

    // Upper hull
    size_t t = hull.size() + 1;
    for (int i = in.size() - 2; i >= 0; i--) {
        pii p = in[i];
        while (hull.size() >= t && !turnRight(hull[hull.size() - 2], hull[hull.size() - 1], p))
            hull.pop_back();
        hull.push_back(p);
    }


    return hull;
}

double distToLine(pii p1, pii p2, pii p) {
    double num = abs((p2.second - p1.second) * p.first - (p2.first - p1.first) * p.second + p2.first * p1.second - p2.second * p1.first);
    double den = sqrt(pow(p2.second - p1.second, 2) + pow(p2.first - p1.first, 2));
    return num / den;
}

double rotatingCalipers(vector<pii> &hull) {
    int n = hull.size();
    if (n == 2) return sqrt(pow(hull[0].first - hull[1].first, 2) + pow(hull[0].second - hull[1].second, 2));
    
    double minWidth = INFINITY;
    for (int i = 0, k = 1; i < n; i++) {
        while (distToLine(hull[i], hull[(i + 1) % n], hull[(k + 1) % n]) > distToLine(hull[i], hull[(i + 1) % n], hull[k]))
            k = (k + 1) % n;
        minWidth = min(minWidth, distToLine(hull[i], hull[(i + 1) % n], hull[k]));
    }
    return minWidth;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if(DEBUG){
        freopen("sample-C_.1.in", "r", stdin);
    }
    long n, r;
    cin >> n >> r;

    vector<pii> in(n);
    for (long i = 0; i < n; i++) {
        cin >> in[i].first >> in[i].second;
    }

    vector<pii> hull = convexHull(in);
    if(DEBUG){
        for(auto p: hull){
            cout << p.first << " " << p.second << endl;
        }
    }
    double minWidth = rotatingCalipers(hull);

    cout.precision(15);
    cout << fixed << minWidth << endl;
    return 0;
}
