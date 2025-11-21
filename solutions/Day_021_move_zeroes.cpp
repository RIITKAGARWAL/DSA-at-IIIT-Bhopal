/**
 * Problem: Move Zeroes
 * Day: 21 / 288
 * Category: Two Pointers
 * Approach: Writer and reader pointer swap
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writePtr = 0;
        for (int readPtr = 0; readPtr < (int)nums.size(); ++readPtr) {
            if (nums[readPtr] != 0) {
                swap(nums[writePtr++], nums[readPtr]);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12}; s.moveZeroes(nums);

    cout << "Passed test for Move Zeroes" << endl;
    return 0;
}
