/**
 * Problem: Evaluate Reverse Polish Notation
 * Day: 33 / 288
 * Category: Stack
 * Approach: Operand evaluation with stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (const string& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                if (t == "+") st.push(a + b);
                else if (t == "-") st.push(a - b);
                else if (t == "*") st.push(a * b);
                else if (t == "/") st.push(a / b);
            } else {
                st.push(stoll(t));
            }
        }
        return st.top();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> tokens = {"2", "1", "+", "3", "*"}; int res = s.evalRPN(tokens);

    cout << "Passed test for Evaluate Reverse Polish Notation" << endl;
    return 0;
}
