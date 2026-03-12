/**
 * Problem: Number of 1 Bits
 * Day: 132 / 288
 * Category: Bit Manipulation
 * Approach: Brian Kernighan's Algorithm
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    uint32_t n = 11; int res = s.hammingWeight(n);

    cout << "Passed test for Number of 1 Bits" << endl;
    return 0;
}
