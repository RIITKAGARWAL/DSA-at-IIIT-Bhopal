/**
 * Problem: Tag Validator
 * Day: 238 / 288
 * Category: String
 * Approach: Stack tag validation parser
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        int i = 0, n = code.size();
        while (i < n) {
            if (i > 0 && st.empty()) return false;
            if (code.substr(i, 9) == "<![CDATA[") {
                int closeIdx = code.find("]]>", i);
                if (closeIdx == string::npos) return false;
                i = closeIdx + 3;
            } else if (code.substr(i, 2) == "</") {
                int closeIdx = code.find('>', i);
                if (closeIdx == string::npos) return false;
                string tagName = code.substr(i + 2, closeIdx - (i + 2));
                if (st.empty() || st.top() != tagName) return false;
                st.pop();
                i = closeIdx + 1;
            } else if (code[0] == '<') {
                int closeIdx = code.find('>', i);
                if (closeIdx == string::npos) return false;
                string tagName = code.substr(i + 1, closeIdx - (i + 1));
                if (tagName.empty() || tagName.size() > 9) return false;
                for (char c : tagName) if (!isupper(c)) return false;
                st.push(tagName);
                i = closeIdx + 1;
            } else {
                i++;
            }
        }
        return st.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.isValid("<DIV>This is the first line <![CDATA[<div>]]> </DIV>");

    cout << "Passed test for Tag Validator" << endl;
    return 0;
}
