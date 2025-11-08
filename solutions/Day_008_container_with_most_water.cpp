/**
 * Problem: Container With Most Water
 * Day: 8 / 288
 * Category: Two Pointers
 * Approach: Inward shrinkage greedy scan
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxWater = 0;
        while (l < r) {
            int w = r - l;
            int h = min(height[l], height[r]);
            maxWater = max(maxWater, w * h);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7}; int res = s.maxArea(h);

    cout << "Passed test for Container With Most Water" << endl;
    return 0;
}
