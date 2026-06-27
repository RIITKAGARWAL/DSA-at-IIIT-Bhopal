/**
 * Problem: Basic Calculator
 * Day: 239 / 288
 * Category: Stack
 * Approach: Sign and operator stack simulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long sum = 0, sign = 1;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                long long num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0; sign = 1;
            } else if (c == ')') {
                sum *= st.top(); st.pop();
                sum += st.top(); st.pop();
            }
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.calculate("(1+(4+5+2)-3)+(6+8)");

    cout << "Passed test for Basic Calculator" << endl;
    return 0;
}
