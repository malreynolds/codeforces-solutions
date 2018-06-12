#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();


    if (n < 3) { cout << "No" << endl; return 0; }

    bool ans = false;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'C') {
            if ((s[i - 1] == 'A' && s[i + 1] == 'B') ||
                (s[i - 1] == 'B' && s[i + 1] == 'A')) {
                    ans = true;
                    break;
            }
        } else if (s[i] == 'A') {
            if ((s[i - 1] == 'B' && s[i + 1] == 'C') ||
                (s[i - 1] == 'C' && s[i + 1] == 'B')) {
                    ans = true;
                    break;
            }
        } else if (s[i] == 'B') {
            if ((s[i - 1] == 'A' && s[i + 1] == 'C') ||
                (s[i - 1] == 'C' && s[i + 1] == 'A')) {
                    ans = true;
                    break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}