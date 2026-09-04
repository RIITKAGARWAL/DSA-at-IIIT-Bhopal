#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxW = 0, n = height.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                maxW = max(maxW, min(height[i], height[j]) * (j - i));
            }
        }
        return maxW;
    }
};