#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int check(vector<string> b, int num) {
    int cnt = 0;
    int n = b.size();
    char c;
    for (int i = 0; i < n; i++) {
        if (i % 2 == num) c = '1';
        else c = '0';
        for (int j = 0; j < n; j++) {
            if (b[i][j] != c) {
                cnt++;
            }
            if (c == '1') c = '0';
            else c = '1';
        }
    }
    return cnt;
}

int odd(vector<string> b) {
    return check(b, 0);
}

int even(vector<string> b){
    return check(b, 1);
}

int main() {
    int n;
    cin >> n;
    string x; 
    vector<vector<string> > s(4);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            s[i].push_back(x);
        }
    }
    cout<< min({
        odd(s[0]) + odd(s[1]) + even(s[2]) + even(s[3]),
        odd(s[0]) + even(s[1]) + odd(s[2]) + even(s[3]),
        odd(s[0]) + even(s[1]) + even(s[2]) + odd(s[3]),
        even(s[0]) + odd(s[1]) + even(s[2]) + odd(s[3]),
        even(s[0]) + even(s[1]) + odd(s[2]) + odd(s[3]),
        even(s[0]) + odd(s[1]) + odd(s[2]) + even(s[3])
    }) << endl;

    return 0;
}