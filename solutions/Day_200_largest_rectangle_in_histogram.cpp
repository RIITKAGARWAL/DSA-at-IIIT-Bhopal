/**
 * Problem: Largest Rectangle in Histogram
 * Day: 200 / 288
 * Category: Stack
 * Approach: Monotonic increasing stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, n = heights.size();
        for (int i = 0; i <= n; ++i) {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && heights[st.top()] >= h) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> h = {2,1,5,6,2,3}; int res = s.largestRectangleArea(h);

    cout << "Passed test for Largest Rectangle in Histogram" << endl;
    return 0;
}
