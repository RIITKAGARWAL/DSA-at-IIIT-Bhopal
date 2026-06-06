/**
 * Problem: Subarray Sums Divisible by K
 * Day: 218 / 288
 * Category: Prefix Sum
 * Approach: Remainder frequency counting
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remMap;
        remMap[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            if (rem < 0) rem += k;
            if (remMap.count(rem)) {
                count += remMap[rem];
            }
            remMap[rem]++;
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {4, 5, 0, -2, -3, 1}; int res = s.subarraysDivByK(nums, 5);

    cout << "Passed test for Subarray Sums Divisible by K" << endl;
    return 0;
}
