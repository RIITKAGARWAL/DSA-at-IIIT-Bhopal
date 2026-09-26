#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        for (int i = 0; i < n; ++i) {
            int minH = heights[i];
            for (int j = i; j < n; ++j) {
                minH = min(minH, heights[j]);
                maxArea = max(maxArea, minH * (j - i + 1));
            }
        }
        return maxArea;
    }
};