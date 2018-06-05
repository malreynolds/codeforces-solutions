#include <iostream>
#include <algorithm>

using namespace std;

int cnt[1001];

int main() {
    int n, m;
    cin >> n >> m;

    int c;
    for (int i = 0; i < m; i++) {
        cin >> c;
        cnt[c]++;
    }
    int ans = 1000;
    for (int i = 1; i <= n; i++) {
        ans = min(cnt[i], ans);
    }

    cout << ans << endl;

    return 0;
}