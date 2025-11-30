/**
 * Problem: Subarray Sum Equals K
 * Day: 30 / 288
 * Category: Arrays
 * Approach: Prefix sum with hash map frequencies
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;
            if (prefixMap.find(sum - k) != prefixMap.end()) {
                count += prefixMap[sum - k];
            }
            prefixMap[sum]++;
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
