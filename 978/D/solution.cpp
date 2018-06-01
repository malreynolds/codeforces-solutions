#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n);
    map<int, vector<int> > differences;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (b.size() <= 2) cout << 0 << endl;

    int mean = 0; 
    for (int i = 1; i < n; i++) {
        int diff = abs(b[i] - b[i - 1]);
        mean += diff;
        differences[diff].push_back(i);
    }
    mean = round((double)mean / (n - 1));

    // cout << mean << endl;
    int count = 0;

    for (int i = 1, j = 0, k = 2; i < n - 1; i++, j++, k++) {
        int left_diff = abs(b[i] - b[j]);
        int right_diff = abs(b[i] - b[k]);

        if (abs(mean - left_diff) > 2 || abs(mean - right_diff) > 2) {
            cout << -1 << endl;
            return 0;
        }
        cout << left_diff << " " << right_diff << endl;
        if (left_diff == mean && right_diff == mean) continue;

        if (left_diff == mean) {
            cout << "right" << endl;
            if (right_diff > mean) {
                if (b[i] > b[k]) {
                    b[k]++;
                } else if (b[i] < b[k]) {
                    b[k]--;
                }
            } else {
                if (b[i] > b[k]) {
                    b[k]--;
                } else if (b[i] < b[k]) {
                    b[k]++;
                }
            }
            count++;
        } else if (right_diff == mean) {
            cout << "left" << endl;
            if (left_diff > mean) {
                if (b[j] > b[i]) {
                    b[j]--;
                } else if (b[j] < b[i]) {
                    b[j]++;
                }
            } else {
                if (b[j] > b[i]) {
                    b[j]++;
                } else if (b[j] < b[i]) {
                    b[j]--;
                }
            }
            count++;
        } else {
            cout << "mid" << endl;
            if (abs(right_diff - left_diff) == 2) {
                if (left_diff > right_diff) {
                    if (b[i] < b[k]) {
                        b[i]--;
                    } else {
                        b[i]++;
                    }
                } else {
                    if (b[i] < b[k]) {
                        b[i]++;
                    } else {
                        b[i]--;
                    }
                }
                count++;
            } else {

            }
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    cout << count << endl;
    return 0;
}

    // for (int i = 0, j = 1; i < n - 1; i++, j++) {
    //     int diff = abs(b[j] - b[i]);
    //     int mean_diff = mean - diff;
    //     if (abs(mean_diff) > 2) {
    //         cout << -1 << endl;
    //         break;
    //     } else if (mean_diff == 2) {
    //         if (b[i] > b[j]) {
    //             b[i]++; b[j]--;
    //         } else {
    //             b[i]--; b[j]++;
    //         }
    //     } else if (mean_diff == -2) {
    //         if (b[i] > b[j]) {
    //             b[i]--; b[j]++;
    //         } else {
    //             b[i]++; b[j]--;
    //         }
    //     } else if (mean_diff == 1) {
            
    //     } else if (mean_diff == -1 ) {

    //     }
    //     count += abs(mean_diff);
    // }