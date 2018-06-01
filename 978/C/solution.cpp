#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    vector<long long> b(m);

    int room_count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        room_count += a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int f = 0;
    long long sum = a[f];
    for (int i = 0; i < m; i++) {
        long long r = b[i];
        while (r > sum) {
            f++;
            sum += a[f];
        }
        cout << f + 1 << " " << r - (sum - a[f]) <<  endl;
        // cout << k << " " << r % a[k] << endl;
    }

    return 0;
}