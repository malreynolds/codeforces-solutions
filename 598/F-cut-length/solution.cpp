#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const long double eps = 1e-9;

inline int sign(long double num) {
    if (num > eps) return 1;
    if (num < -eps) return -1;
    return 0;
}

struct Point {
    long double x, y;
    Point() {}
    Point(long double x, long double y): x(x), y(y) {}
    Point operator + (const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator - (const Point &other) const {
        return Point(x - other.x, y - other.y);
    }

    long double operator ^ (const Point &other) const {
        return x * other.y - y * other.x;
    }

    long double length() const {
        return hypotl(x, y);
    }
};

void solve(vector<Point> polygon, Point p, Point q) {
    int n = polygon.size();

    vector<pair<long double, int>> intersectionPairs;

    for (int i = 0, j = i + 1; i < n; i++, j = (j + 1) % n) {
        int startSign = sign((polygon[i] - p) ^ (q - p));
        int endSign = sign((polygon[j] - p) ^ (q - p));
        if (startSign == endSign) continue;
        long double t = ((polygon[i] - p) ^ (polygon[i] - polygon[j])) / ((q - p) ^ (polygon[i] - polygon[j]));
        intersectionPairs.push_back(make_pair(t, endSign - startSign));
    }

    sort(intersectionPairs.begin(), intersectionPairs.end());

    long double totalT = 0, previousT = 0;
    int count = 0;
    for (auto intersectionPair : intersectionPairs) {
        if (count > 0) totalT += intersectionPair.first - previousT;
        previousT = intersectionPair.first;
        count += intersectionPair.second;
    }

    cout << totalT * (q - p).length() << endl;
}

int main() {
    int n, m;
    cout << fixed << setprecision(12);
    cin >> n >> m;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    long double area = 0;
    for (int i = 0, j = i + 1; i < n; i++, j = (j + 1) % n) {
        area += polygon[i] ^ polygon[j];
    }

    if (area < 0) reverse(polygon.begin(), polygon.end());

    for (int i = 0; i < m; i++) {
        Point p, q;
        cin >> p.x >> p.y >> q.x >> q.y;
        solve(polygon, p, q);
    }
}