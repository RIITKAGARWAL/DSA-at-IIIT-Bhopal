/**
 * Problem: Trapping Rain Water
 * Day: 9 / 288
 * Category: Two Pointers
 * Approach: Left and right max boundaries
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, total = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= leftMax) leftMax = height[l];
                else total += leftMax - height[l];
                l++;
            } else {
                if (height[r] >= rightMax) rightMax = height[r];
                else total += rightMax - height[r];
                r--;
            }
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; int res = s.trap(h);

    cout << "Passed test for Trapping Rain Water" << endl;
    return 0;
}
