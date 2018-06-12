#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    
    if (a == b) { cout << 1 << endl; return 0; }

    long long c = b - a;

    bool hasTwo = (c >= 2) ? true : (b % 2 == 0);
    bool hasFive = false;
    long long d = 1;
    for (long long c = b - (b - a) + 1; c <= b; c++) {
        if (c % 5 == 0) {
            hasFive = true;
            break;
        } else {
            d *= c % 10;
        }
    }

    if (hasFive) {
        if (hasTwo) cout << 0 << endl;
        else cout << 5 << endl;
    } else {
        cout << d % 10 << endl;
    }

    return 0;
}