/**
 * Problem: Majority Element
 * Day: 25 / 288
 * Category: Arrays
 * Approach: Boyer-Moore Voting Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2}; int res = s.majorityElement(nums);

    cout << "Passed test for Majority Element" << endl;
    return 0;
}
