/**
 * Problem: Trapping Rain Water
 * Day: 201 / 288
 * Category: Two Pointers
 * Approach: Left and Right Max boundaries
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0, maxL = 0, maxR = 0;
        while (l <= r) {
            if (height[l] <= height[r]) {
                maxL = max(maxL, height[l]);
                res += maxL - height[l];
                l++;
            } else {
                maxR = max(maxR, height[r]);
                res += maxR - height[r];
                r--;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1}; int res = s.trap(h);

    cout << "Passed test for Trapping Rain Water" << endl;
    return 0;
}
