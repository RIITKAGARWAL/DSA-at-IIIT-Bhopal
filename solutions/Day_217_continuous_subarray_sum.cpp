/**
 * Problem: Continuous Subarray Sum
 * Day: 217 / 288
 * Category: Prefix Sum
 * Approach: Modulo remainder prefix map
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remMap;
        remMap[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int rem = (k == 0) ? sum : sum % k;
            if (remMap.count(rem)) {
                if (i - remMap[rem] > 1) return true;
            } else {
                remMap[rem] = i;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {23, 2, 4, 6, 7}; bool res = s.checkSubarraySum(nums, 6);

    cout << "Passed test for Continuous Subarray Sum" << endl;
    return 0;
}
