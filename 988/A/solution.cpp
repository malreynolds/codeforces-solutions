#include <map>
#include <iostream>

using namespace std;

int main() {
    int n, k, r;
    cin >> n >> k;
    map<int, int> a;
    for (int i = 1; i <= n; i++) {
        cin >> r;
        a[r] = i;
    }

    if (a.size() >= k) {
        cout << "YES" << endl;
        for (auto i : a) {
            k--;
            cout << i.second << " ";
            if (k == 0) break;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}