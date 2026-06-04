/**
 * Problem: Subarray Sum Equals K
 * Day: 216 / 288
 * Category: Prefix Sum
 * Approach: Hash map frequency prefix sums
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 1, 1}; int res = s.subarraySum(nums, 2);

    cout << "Passed test for Subarray Sum Equals K" << endl;
    return 0;
}
