/**
 * Problem: Plus One
 * Day: 140 / 288
 * Category: Math
 * Approach: Cascading carry via array iteration
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> digits = {1, 2, 3}; auto res = s.plusOne(digits);

    cout << "Passed test for Plus One" << endl;
    return 0;
}
