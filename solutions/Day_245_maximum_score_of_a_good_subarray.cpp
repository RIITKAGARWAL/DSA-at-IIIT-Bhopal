/**
 * Problem: Maximum Score of a Good Subarray
 * Day: 245 / 288
 * Category: Array / Greedy
 * Approach: Two pointer minimum boundary expansion
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int l = k, r = k, minVal = nums[k], maxScore = nums[k];
        int n = nums.size();
        while (l > 0 || r < n - 1) {
            if (l == 0 || (r < n - 1 && nums[r + 1] > nums[l - 1])) {
                r++;
                minVal = min(minVal, nums[r]);
            } else {
                l--;
                minVal = min(minVal, nums[l]);
            }
            maxScore = max(maxScore, minVal * (r - l + 1));
        }
        return maxScore;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 4, 3, 7, 4, 5}; int res = s.maximumScore(nums, 3);

    cout << "Passed test for Maximum Score of a Good Subarray" << endl;
    return 0;
}
