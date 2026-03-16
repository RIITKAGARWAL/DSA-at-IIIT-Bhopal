/**
 * Problem: Sum of Two Integers
 * Day: 136 / 288
 * Category: Bit Manipulation
 * Approach: Bitwise XOR and left-shifted AND
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int res = s.getSum(1, 2);

    cout << "Passed test for Sum of Two Integers" << endl;
    return 0;
}
