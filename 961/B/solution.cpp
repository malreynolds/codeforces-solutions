#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sums[100001];

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> t(n);
    cin >> t[0];
    int ans = t[0] ? a[0] : 0; 
    sums[0] = !t[0] ? a[0] : 0;
    for (int i = 1; i < n; i++) {
        cin >> t[i];
        if (t[i]) { ans += a[i]; sums[i] += sums[i-1]; }
        else sums[i] += (a[i] + sums[i-1]);
    }
    int bestSum = sums[k - 1];
    for (int i = k; i < n; i++) {
        bestSum = max(bestSum, sums[i] - sums[i - k]);
    }
    ans += bestSum;

    cout << ans << endl;

    return 0;
}