#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    string sub = "xxx";

    vector<size_t> positions; // holds all the positions that sub occurs within str

    size_t pos = str.find(sub, 0);
    while(pos != string::npos)
    {
        positions.push_back(pos);
        pos = str.find(sub,pos+1);
    }
    
    cout << positions.size() << endl;

    return 0;
}