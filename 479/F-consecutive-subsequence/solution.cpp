#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> l(n);

    l[0].push_back(1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] + 1 == a[i]) {
                if (l[i].size() < l[j].size() + 1)
                    l[i] = l[j];
            }
        }
        l[i].push_back(i+1);
    }

    int k = 0, bestI = 0;
    for (int i = 0; i < n; i++) {
        if (k < l[i].size()) {
            k = l[i].size();
            bestI = i;
        }
    }
    
    cout << k << endl;
    cout << l[bestI][0];
    for (int j = 1; j < k; j++) {
        cout << " " << l[bestI][j]; 
    }
    cout << endl;
    return 0;
}

