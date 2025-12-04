/**
 * Problem: Daily Temperatures
 * Day: 34 / 288
 * Category: Monotonic Stack
 * Approach: Monotonic decreasing index stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73}; auto res = s.dailyTemperatures(temps);

    cout << "Passed test for Daily Temperatures" << endl;
    return 0;
}
