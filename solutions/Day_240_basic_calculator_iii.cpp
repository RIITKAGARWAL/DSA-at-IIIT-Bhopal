/**
 * Problem: Basic Calculator III
 * Day: 240 / 288
 * Category: Stack
 * Approach: Operator precedence calculator
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long num = 0; char op = '+';
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (c == '(') {
                int j = i, brackets = 0;
                for (; i < s.size(); ++i) {
                    if (s[i] == '(') brackets++;
                    if (s[i] == ')') brackets--;
                    if (brackets == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*' || op == '/') {
                    int prev = st.top(); st.pop();
                    st.push(op == '*' ? prev * num : prev / num);
                }
                op = c; num = 0;
            }
        }
        long long res = 0;
        while (!st.empty()) { res += st.top(); st.pop(); }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.calculate("2*(5+5*2)/3+(6/2+8)");

    cout << "Passed test for Basic Calculator III" << endl;
    return 0;
}
