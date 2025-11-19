/**
 * Problem: Two Sum II - Input Array Is Sorted
 * Day: 19 / 288
 * Category: Two Pointers
 * Approach: Opposite-end pointer scanning
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            if (sum < target) l++;
            else r--;
        }
        return {};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> numbers = {2, 7, 11, 15}; auto res = s.twoSum(numbers, 9);

    cout << "Passed test for Two Sum II - Input Array Is Sorted" << endl;
    return 0;
}
