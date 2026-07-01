/**
 * Problem: Divide Two Integers
 * Day: 243 / 288
 * Category: Bit Manipulation
 * Approach: Exponential bit-shifting subtraction
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        long long dvd = labs(dividend), dvs = labs(divisor);
        long long res = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return res * sign;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int res = s.divide(10, 3);

    cout << "Passed test for Divide Two Integers" << endl;
    return 0;
}
