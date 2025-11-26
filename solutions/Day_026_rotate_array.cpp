/**
 * Problem: Rotate Array
 * Day: 26 / 288
 * Category: Arrays
 * Approach: Triple array reversal
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7}; s.rotate(nums, 3);

    cout << "Passed test for Rotate Array" << endl;
    return 0;
}
