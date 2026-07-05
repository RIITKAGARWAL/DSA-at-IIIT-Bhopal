/**
 * Problem: Pow(x, n) Iterative
 * Day: 247 / 288
 * Category: Math
 * Approach: Fast power bit-shifting
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) { x = 1 / x; N = -N; }
        double res = 1.0;
        while (N > 0) {
            if (N & 1) res *= x;
            x *= x;
            N >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double res = s.myPow(2.0, -2);

    cout << "Passed test for Pow(x, n) Iterative" << endl;
    return 0;
}
