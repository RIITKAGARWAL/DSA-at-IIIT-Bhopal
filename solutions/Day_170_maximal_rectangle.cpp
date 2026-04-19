/**
 * Problem: Maximal Rectangle
 * Day: 170 / 288
 * Category: Dynamic Programming
 * Approach: Row-by-row histogram evaluation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; int maxA = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()]; st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxA = max(maxA, h * w);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxA;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> heights(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<char>> m = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}}; int res = s.maximalRectangle(m);

    cout << "Passed test for Maximal Rectangle" << endl;
    return 0;
}
