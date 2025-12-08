/**
 * Problem: Simplify Path
 * Day: 38 / 288
 * Category: Stack
 * Approach: Directory token parsing stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;
            if (token == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }
        string res = "";
        for (const string& dir : st) res += "/" + dir;
        return res.empty() ? "/" : res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.simplifyPath("/home//foo/");

    cout << "Passed test for Simplify Path" << endl;
    return 0;
}
