#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> dp;

    int k = 0, first = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        dp[x] = dp[x - 1] + 1;
        if (k < dp[x]) {
            k = dp[x];
            first = x;
        }
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == first) {
            ans.push_back(i);
            first--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << k << endl;
    for (auto i: ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}

