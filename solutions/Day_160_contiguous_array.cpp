/**
 * Problem: Contiguous Array
 * Day: 160 / 288
 * Category: Hash Table
 * Approach: Prefix sum balancing
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> pos;
        pos[0] = -1;
        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += (nums[i] == 1 ? 1 : -1);
            if (pos.find(count) != pos.end()) {
                maxLen = max(maxLen, i - pos[count]);
            } else {
                pos[count] = i;
            }
        }
        return maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {0, 1, 0}; int res = s.findMaxLength(nums);

    cout << "Passed test for Contiguous Array" << endl;
    return 0;
}
