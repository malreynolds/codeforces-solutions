#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long double PI = atan(1) * 4;

struct PointVector {
    long double angle;
    int i;
};

bool cmp(PointVector a, PointVector b) {
    return a.angle < b.angle;
}

int main()
{
    int n, a, b, x, y;
    long double bestAns, currentAns;
    cin >> n;
    vector<PointVector> vectors(n);
    for (int i = 0; i < n; i++) {
        vectors[i].i = i + 1;
        cin >> x >> y;
        vectors[i].angle = atan2(y, x);
    }
    sort(vectors.begin(), vectors.end(), cmp);
    
    bestAns = (2 * PI - abs(vectors[0].angle) - abs(vectors[n - 1].angle));
    a = vectors[0].i; b = vectors[n-1].i;
    for (int i = 0; i < n - 1; i++) {
        currentAns = vectors[i + 1].angle - vectors[i].angle;
        if (currentAns < bestAns) {
            bestAns = currentAns;
            a = vectors[i].i;
            b = vectors[i + 1].i;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}