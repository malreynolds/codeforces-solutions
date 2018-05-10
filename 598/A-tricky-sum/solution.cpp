#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    long long n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        long long sum = n * (n + 1) / 2, power_sum = 0;
        for (long long j = 1; j <= n; j *= 2) {
            power_sum += j;
        }
        cout << sum  - power_sum * 2 << endl;
    }
    return 0;
}