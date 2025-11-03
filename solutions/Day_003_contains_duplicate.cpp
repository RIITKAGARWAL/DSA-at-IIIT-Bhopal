/**
 * Problem: Contains Duplicate
 * Day: 3 / 288
 * Category: Arrays
 * Approach: Hash Set frequency check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return true;
            seen.insert(x);
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1, 2, 3, 1}; bool res = s.containsDuplicate(nums);

    cout << "Passed test for Contains Duplicate" << endl;
    return 0;
}
