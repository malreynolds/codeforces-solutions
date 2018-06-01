#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX 3e8


using namespace std;

long long dp[3001];

int main() {
    int n;
    cin >> n;
    vector<long long> s(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        dp[i] = MAX + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] < s[j])
                dp[j] = min(dp[j], c[i] + c[j]);
        }
    }

    long long bestCost = MAX + 1;
    for (int j = 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if (s[j] < s[k])
                bestCost = min(bestCost, dp[j] + c[k]);
        }
    }

    if (bestCost == MAX + 1) cout << -1 << endl;
    else cout << bestCost << endl;

    return 0;
}   