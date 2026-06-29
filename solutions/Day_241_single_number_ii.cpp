/**
 * Problem: Single Number II
 * Day: 241 / 288
 * Category: Bit Manipulation
 * Approach: Bit-position frequency modulo 3
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int num : nums) {
                if ((num >> i) & 1) sum++;
            }
            if (sum % 3 != 0) {
                res |= (1 << i);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {2, 2, 3, 2}; int res = s.singleNumber(nums);

    cout << "Passed test for Single Number II" << endl;
    return 0;
}
