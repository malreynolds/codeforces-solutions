#include <iostream>
#include <string>

using namespace std;

char negative(char c) {
    return ((c == '1') ? '0' : '1');
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    for (int i = 0; i < n - p; i++) {
        if (s[i] == '.' && s[i+p] == '.') {
            s[i] = '1'; s[i + p] = '0';
        } else if (s[i] == '.') {
            s[i] = negative(s[i+p]);
        } else if (s[i+p] == '.') {
            s[i+p] = negative(s[i]);
        }
    }

    bool possible = false;
    for (int i = 0; i < n - p; i++) {
        if (s[i] != s[i + p]) {
            possible = true;
            break;
        }
    }


    for (int i = n - p; i < n - (n - p); i++) {
        if (s[i] == '.') s[i] = '0';
    }


    cout << (possible ? s : "No") << endl;
    return 0;
}