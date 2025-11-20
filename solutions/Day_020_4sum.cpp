/**
 * Problem: 4Sum
 * Day: 20 / 288
 * Category: Two Pointers
 * Approach: Generalized K-Sum recursive reduction
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long t = (long long)target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long long s = nums[l] + nums[r];
                    if (s == t) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++; r--;
                    } else if (s < t) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2}; auto res = s.fourSum(nums, 0);

    cout << "Passed test for 4Sum" << endl;
    return 0;
}
