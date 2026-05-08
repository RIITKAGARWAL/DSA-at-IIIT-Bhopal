/**
 * Problem: Sliding Window Median
 * Day: 189 / 288
 * Category: Heap
 * Approach: Two multisets (Min/Max Heap)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        vector<double> res;
        auto balance = [&]() {
            if (left.size() > right.size() + 1) {
                right.insert(*left.rbegin());
                left.erase(prev(left.end()));
            } else if (right.size() > left.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        };
        for (int i = 0; i < nums.size(); ++i) {
            if (left.empty() || nums[i] <= *left.rbegin()) left.insert(nums[i]);
            else right.insert(nums[i]);
            if (i >= k) {
                int out = nums[i - k];
                if (out <= *left.rbegin()) left.erase(left.find(out));
                else right.erase(right.find(out));
            }
            balance();
            if (i >= k - 1) {
                if (k % 2 == 1) res.push_back(*left.rbegin());
                else res.push_back(((double)*left.rbegin() + *right.begin()) / 2.0);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7}; auto res = s.medianSlidingWindow(nums, 3);

    cout << "Passed test for Sliding Window Median" << endl;
    return 0;
}
