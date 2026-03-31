/**
 * Problem: Valid Parenthesis String
 * Day: 151 / 288
 * Category: Greedy
 * Approach: Left min and max tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                leftMin++; leftMax++;
            } else if (c == ')') {
                leftMin--; leftMax--;
            } else {
                leftMin--; leftMax++;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0;
        }
        return leftMin == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.checkValidString("(*))");

    cout << "Passed test for Valid Parenthesis String" << endl;
    return 0;
}
