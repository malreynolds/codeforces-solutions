#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool solve(long long num, int n, int i, vector<long long> &ans, unordered_set<long long> &s) {
    if (s.find(num) == s.end()) return false;
    ans[i] = num;
    if (i == n - 1) return true;
    if (num % 3 == 0) return solve(num / 3, n, i + 1, ans, s) || solve(num * 2, n, i + 1, ans, s);
    else return solve(num * 2, n, i + 1, ans, s);
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<long long> s(a.begin(), a.end());
    vector<long long> ans(n);

    for (int i = 0; i < n; i++) {
        if (solve(a[i], n, 0, ans, s)) {
            cout << ans[0];
            for (int j = 1; j < n; j++) {
                cout << " " << ans[j];
            }
            cout << endl;
            break;
        }
    }
    return 0;
}
