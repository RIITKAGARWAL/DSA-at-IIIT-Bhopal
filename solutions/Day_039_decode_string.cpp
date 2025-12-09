/**
 * Problem: Decode String
 * Day: 39 / 288
 * Category: Stack
 * Approach: Dual count and string buffer stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;
        string curStr = "";
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countSt.push(k);
                strSt.push(curStr);
                curStr = "";
                k = 0;
            } else if (c == ']') {
                int repeat = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();
                string temp = "";
                while (repeat--) temp += curStr;
                curStr = prev + temp;
            } else {
                curStr += c;
            }
        }
        return curStr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.decodeString("3[a]2[bc]");

    cout << "Passed test for Decode String" << endl;
    return 0;
}
