/**
 * Problem: Daily Temperatures
 * Day: 202 / 288
 * Category: Stack
 * Approach: Monotonic decreasing stack
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
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                res[st.top()] = i - st.top();
                st.pop();
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
    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73}; auto res = s.dailyTemperatures(t);

    cout << "Passed test for Daily Temperatures" << endl;
    return 0;
}
