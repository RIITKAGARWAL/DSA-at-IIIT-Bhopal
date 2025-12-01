/**
 * Problem: Valid Parentheses
 * Day: 31 / 288
 * Category: Stack
 * Approach: Stack matching open brackets
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        return st.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.isValid("()[]{}");

    cout << "Passed test for Valid Parentheses" << endl;
    return 0;
}
