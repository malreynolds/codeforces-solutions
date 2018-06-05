#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    cout << (n / k) * (m / k) + ((n % k) ? (m / k) : 0) + ((m % k) ? (n / k) : 0) + (m % k && n % k) << endl;

    return 0;
}