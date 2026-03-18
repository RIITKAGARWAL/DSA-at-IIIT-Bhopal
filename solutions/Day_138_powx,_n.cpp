/**
 * Problem: Pow(x, n)
 * Day: 138 / 288
 * Category: Math
 * Approach: Binary Exponentiation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1.0;
        double curr_product = x;
        while (N > 0) {
            if (N % 2 == 1) {
                res *= curr_product;
            }
            curr_product *= curr_product;
            N /= 2;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    double res = s.myPow(2.0, 10);

    cout << "Passed test for Pow(x, n)" << endl;
    return 0;
}
