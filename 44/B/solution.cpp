#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int> > compact(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = a[i].at(j) - '0';
            if (c == 1) {
                compact[i].push_back(j);
            }
        }
    }

    vector<int> lamp_sums(m);
    bool found;
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int c = a[i].at(j) - '0';
            sum += c;
        }
        lamp_sums[j] = sum;
    }

    
    for (int i = 0; i < n; i++) {
        vector<int> sums(lamp_sums);
        vector<int> lamps = compact[i];
        for (auto lamp : lamps) {
            sums[lamp]--;
        }

        found = true;
        for (auto sum : sums) {
            if (sum == 0)
                found = false;
        }
        if (found) break;
    }

    if (found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}