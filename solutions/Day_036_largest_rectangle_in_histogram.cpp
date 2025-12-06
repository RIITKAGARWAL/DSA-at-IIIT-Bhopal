/**
 * Problem: Largest Rectangle in Histogram
 * Day: 36 / 288
 * Category: Monotonic Stack
 * Approach: Monotonic increasing stack boundaries
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), maxArea = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
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
    vector<int> heights = {2, 1, 5, 6, 2, 3}; int res = s.largestRectangleArea(heights);

    cout << "Passed test for Largest Rectangle in Histogram" << endl;
    return 0;
}
