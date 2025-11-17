/**
 * Problem: Encode and Decode Strings
 * Day: 17 / 288
 * Category: Strings
 * Approach: Length prefix delimiter encoding
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) res += to_string(s.size()) + "#" + s;
        return res;
    }
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < (int)s.size()) {
            int hashPos = s.find('#', i);
            int len = stoi(s.substr(i, hashPos - i));
            res.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> vs = {"lint", "code", "love", "you"}; string e = s.encode(vs); auto res = s.decode(e);

    cout << "Passed test for Encode and Decode Strings" << endl;
    return 0;
}
