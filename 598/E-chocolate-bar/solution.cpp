#include <iostream>

using namespace std;

int dp[31][31][51];

int cost(int n, int m, int k) {

    if (dp[n][m][k] || k == 0 || n * m == k) return dp[n][m][k];

    int bestMin = 1e9;
    for (int i = 1; i <= n - i; i++) {
        for (int j = 0; j <= k; j++) {
            bestMin = min(bestMin, cost(i, m, j) + cost(n - i, m, k - j) + m * m);
        }
    }

    for (int i = 1; i <= m - i; i++) {
        for (int j = 0; j <= k; j++) {
            bestMin = min(bestMin, cost(n, i, j) + cost(n, m - i, k - j) + n * n);
        }
    }

    return dp[n][m][k] = bestMin; 
}

int main() {
    int t;
    cin >> t;
    int n, m, k;
    while(t--) {
        cin >> n >> m >> k;
        cout << cost(n, m, k) << endl;
    } 
}