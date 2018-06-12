#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> numbers = {a, b, c, d};
    sort(numbers.begin(), numbers.end());

    vector<string> ans;

    int biggest = numbers[3];
    int secondBiggest = numbers[2];
    int smallest = numbers[0];
    int secondSmallest = numbers[1];


    string currentAns;
    bool temp = false;
    while (biggest && secondBiggest) {
        biggest--;
        secondBiggest--;
        currentAns += (temp ? '34' : '43');
        if (currentAns.size() == 50) {
            temp = !temp;
            ans.push_back(currentAns);
            currentAns = "";
        }
    }

    while (biggest && secondSmallest) {
        biggest--;
        secondBiggest--;
        currentAns += (temp ? '34' : '43');
        if (currentAns.size() == 50) {
            temp = !temp;
            ans.push_back(currentAns);
            currentAns = "";
        }
    }

    if (currentAns != "") {
        string addition = ((currentAns[currentAns.size() - 1] == '3') ? "4" : "3");
        while(biggest--) {
            currentAns += addition;
        }
        ans.push_back(currentAns);
    }



    int n, m;
    cout << n << " " << m << endl;

    return 0;
}