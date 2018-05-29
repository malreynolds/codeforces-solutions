#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n / 2;
    vector<int> p(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int b_count = 0;
    for (int i = 1, j = 2; i <= m; i++, j+=2) {
        b_count += abs(p[i] - j);
    }

    int w_count = 0;
    for (int i = 1, j = 1; i <= m; i++, j+=2) {
        w_count += abs(p[i] - j);
    }


    cout << min(b_count, w_count) << endl;
    return 0;
}