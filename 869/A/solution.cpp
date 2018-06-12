#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> num_set;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        num_set.insert(x[i]);
    }

    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        num_set.insert(y[i]);
    }

    int cnt = 0;    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num_set.find(x[i] ^ y[j]) != num_set.end()) {
                cnt++;
            }
        }
    }

    if (cnt % 2) cout << "Koyomi" << endl;
    else cout << "Karen" << endl;

    return 0;
}