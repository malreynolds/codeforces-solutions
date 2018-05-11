#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* static void my_rotate(int start, int middle, int end, string &s) {
    if (middle == end) return;
    int next = middle;
    while (start < next) {
        swap(s[start++],  s[next++]);
        if (next == end) next = middle;
        else if (start == middle) middle = next;
    }
} */

int main() {
    string s;
    cin >> s;

    int m, l, r, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        k = k % (r - l + 1);
        rotate(s.begin() + l - 1, s.begin() + r - k, s.begin() + r);
        // my_rotate(l - 1, r - k, r, s);
    }
    cout << s << endl;
    return 0;
}