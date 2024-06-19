#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <complex>
#define DEBUG 1

using namespace std;
const int MAXN = 500;
typedef pair<int, int> Point;
vector<pair<Point, bool>> mooes;
vector<Point> gophers;
double distance(Point a, Point b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
bool compare(pair<Point, bool> a, pair<Point, bool> b)
{
    return (a.first.first == b.first.first) ? (a.first.second < b.first.second) : (a.first.first < b.first.first);
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}
vector<pair<Point, bool>> convexHull(vector<pair<Point, bool>> points)
{
    int n = points.size();
    if (n < 3)
        return {};
    vector<pair<Point, bool>> hull;
    sort(points.begin(), points.end(), compare);
    int l = 0;
    do
    {
        hull.push_back({points[l].first, points[l].second});
        int next = (l + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[l].first, points[i].first, points[next].first) == 2)
            {
                next = i;
            }
        }
        l = next;
    } while (l != 0);
    return hull;
}
// Test if point p is in polygon P
typedef complex<double> vec;
vector<vec> polygon;
const double PI = acos(-1);
double angle(vec a, vec b)
{
    const double angle = fmod(arg(a) - arg(b), 2 * PI);
    if (angle <= PI)
        return angle;
    return angle - 2 * PI;
}
bool windingNumber(vec p)
{
    double totalArg = 0;
    vec last = polygon.back();
    for (auto cur : polygon)
    {
        totalArg += angle(cur - p, last - p);
        last = cur;
    }
    return fabs(fmod(totalArg / (2 * PI), 2)) < 0.1;
}
int main()
{
    if (DEBUG)
    {
        freopen("sample-G.1.in", "r", stdin);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        char c;
        cin >> c;
        Point p = {x, y};
        mooes.push_back({p, c == 'H'});
        if (c == 'G')
        {
            gophers.push_back(p);
        }
    }

    while (true)
    {
        vector<pair<Point, bool>> hull = convexHull(mooes);
        if (DEBUG)
        {
            for (auto p : hull)
            {
                cout << p.first.first << " " << p.first.second << " " << p.second << endl;
            }
        }
        polygon.clear();
        for (auto p : hull)
        {
            polygon.push_back({p.first.first, p.first.second});
        }
        for (auto p : gophers)
        {
            if (windingNumber({p.first, p.second}))
            {
                // Gopher is inside the polygon
                
            }
        }
    }

    

    return 0;
}
