#include <iostream>

using namespace std;

int main() {
    int n, bestCount = 0;
    cin >> n;
    string s, ans;
    cin >> s;

    for (int i = 0; i < n - 1; i++) {
        string substring = s.substr(i, 2);
        size_t pos = s.find(substring, 0);
        int count = 0;
        while(pos != string::npos)
        {
            count++;
            pos = s.find(substring, pos+1);
        }
        if (bestCount < count) {
            bestCount = count;
            ans = substring;
        }
    }
    cout << ans << endl;
    return 0;
}
