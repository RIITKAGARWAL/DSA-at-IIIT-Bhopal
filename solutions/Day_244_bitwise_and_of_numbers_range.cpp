/**
 * Problem: Bitwise AND of Numbers Range
 * Day: 244 / 288
 * Category: Bit Manipulation
 * Approach: Common prefix bit-shifting
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int res = s.rangeBitwiseAnd(5, 7);

    cout << "Passed test for Bitwise AND of Numbers Range" << endl;
    return 0;
}
