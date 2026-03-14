/**
 * Problem: Reverse Bits
 * Day: 134 / 288
 * Category: Bit Manipulation
 * Approach: Bit shift and OR accumulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    uint32_t n = 43261596; uint32_t res = s.reverseBits(n);

    cout << "Passed test for Reverse Bits" << endl;
    return 0;
}
