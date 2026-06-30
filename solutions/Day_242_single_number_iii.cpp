/**
 * Problem: Single Number III
 * Day: 242 / 288
 * Category: Bit Manipulation
 * Approach: Rightmost set bit bucket separation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorAll = 0;
        for (int num : nums) xorAll ^= num;
        long long diffBit = xorAll & -xorAll;
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & diffBit) num1 ^= num;
            else num2 ^= num;
        }
        return {num1, num2};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 2, 1, 3, 2, 5}; auto res = s.singleNumber(nums);

    cout << "Passed test for Single Number III" << endl;
    return 0;
}
