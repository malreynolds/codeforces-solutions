#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

string convert1(string s) {
    int C = s.find('C'), power, col, row, i;
    row = 0; power = 1;
    i = C - 1;
    while (i >= 1) {
        row += (s[i] - '0') * power;
        power *= 10;
        i--;
    }

    power = 1; col = 0;
    i = s.size() - 1;
    while (i > C) {
        col += (s[i] - '0') * power;
        power *= 10;
        i--;
    }
    // cout << col << endl;
    string colAns;
    while (col > 0) {
        char c = 'A' + (col - 1) % 26;
        col--;
        col /= 26;
        colAns += c;
    }
    reverse(colAns.begin(), colAns.end());
    return colAns + to_string(row); 
}

string convert2(string s) {
    int i = 0, col = 0, row = 0, power = 1, j = s.size() - 1;
    vector<int> h;
    while (!isdigit(s[i])) {
        h.push_back(s[i] - 'A' + 1);
        i++;
    }

    reverse(h.begin(), h.end());

    col += h[0];
    for (i = 1; i < h.size(); i++) {
        col += h[i] * 26 * power;
        power *= 26;
    }

    power = 1;
    while(j >= i) {
        row += (s[j] - '0') * power;
        power *= 10;
        j--;
    }
    return "R" + to_string(row) + "C" + to_string(col);
}

int main() {
    int n;
    cin >> n;

    string s;
    while (n--) {
        cin >> s;
        if(s.size() >= 4 && s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos){
            cout << convert1(s) << endl;
        } else {
            cout << convert2(s) << endl;
        }
    }

    return 0;
}