#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, vector<int> > positions;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        positions[a[i]].push_back(i);
    }

    vector<int> ai;
    for (auto e : positions) {
        ai.push_back(e.second[e.second.size() - 1]);
    }

    cout << positions.size() << endl;
    sort(ai.begin(), ai.end());
    for (auto i : ai) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}