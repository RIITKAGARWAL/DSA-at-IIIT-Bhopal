/**
 * Problem: House Robber
 * Day: 103 / 288
 * Category: Dynamic Programming
 * Approach: Rob vs Skip previous house dynamic choice
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int n : nums) {
            int temp = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 2, 3, 1}; int res = s.rob(nums);

    cout << "Passed test for House Robber" << endl;
    return 0;
}
