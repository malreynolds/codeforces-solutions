#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {
    int n;
    cin >> n;
    map<string, string> gem_map;
    gem_map["purple"] = "Power";
    gem_map["green"] = "Time";
    gem_map["blue"] = "Space";
    gem_map["orange"] = "Soul";
    gem_map["red"] = "Reality";
    gem_map["yellow"] = "Mind";


    map<string, int> gem_counts;

    gem_counts["purple"] = 0;
    gem_counts["green"] = 0;
    gem_counts["blue"] = 0;
    gem_counts["orange"] = 0;
    gem_counts["red"] = 0;
    gem_counts["yellow"] = 0;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        gem_counts[s]++;
    }

    cout << 6 - n << endl;
    for( auto e : gem_counts ) {
        if (e.second == 0)
            cout << gem_map[e.first] << endl;
    }
    return 0;
}