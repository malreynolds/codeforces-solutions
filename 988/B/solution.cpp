#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (const string s1, const string s2) {
    if (s2 == s1) return false;
    return s2.find(s1) != string::npos;
}

int main() {
    int n;
    cin >> n;

    vector<string> s;
    
    string x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push_back(x);
    }

    if (s.size() == 1) {
        cout << "YES" << endl;
        cout << x << endl;
    } else {
        sort(s.begin(), s.end(), cmp);

        bool valid = true; 
        for (int i = n - 1; i > 0; i--) {
            if (s[i].find(s[i - 1]) == string::npos) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << "YES" << endl;
            for (auto i : s) {
                cout << i << endl;
            }
        } else cout << "NO" << endl;
    }

    return 0;
}