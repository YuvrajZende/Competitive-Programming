#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string num, s;
    cin >> num >> s;

    if (num.size() != s.size()) {
        cout << "";
        return 0;
    }

    map<char, char> left_right = {
        {'0', '0'}, {'1', '1'}, {'2', '5'}, {'5', '2'}, {'8', '8'}
    };
    map<char, char> up = {
        {'0', '0'}, {'8', '8'}
    };
    map<char, char> down = {
        {'0', '0'}, {'1', '1'}, {'2', '5'}, {'8', '8'}
    };

    vector<char> res;

    for (int i = 0; i < (int)num.size(); i++) {
        char digit = num[i];
        char img = s[i];
        char result = '\0';

        if (img == 'S') result = digit;
        else if (img == 'L' || img == 'R') {
            if (left_right.count(digit)) result = left_right[digit];
        } else if (img == 'D') {
            if (down.count(digit)) result = down[digit];
        } else if (img == 'U') {
            if (up.count(digit)) result = up[digit];
        }

        if (result != '\0') res.push_back(result);
    }

    sort(res.begin(), res.end());

    if (res.size() > 1 && res[0] == '0') {
        for (int i = 1; i < (int)res.size(); i++) {
            if (res[i] != '0') {
                swap(res[0], res[i]);
                break;
            }
        }
    }

    if (res.empty()) {
        cout << "";
    } else {
        for (char c : res) cout << c;
    }

    return 0;
}
