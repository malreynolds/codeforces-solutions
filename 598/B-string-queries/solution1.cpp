#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int m, l, r, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        int substring_size = r - l + 1;
        k = k % substring_size;
        string s2 = s.substr(l - 1, substring_size);
        for (int p = l - 1, j = substring_size - k; 
             p < r; 
             p++, j = (j + 1) % substring_size) {
            s[p] = s2[j];
        }
    }
    cout << s << endl;
    return 0;
}