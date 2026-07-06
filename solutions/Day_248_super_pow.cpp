/**
 * Problem: Super Pow
 * Day: 248 / 288
 * Category: Math
 * Approach: Modular exponentiation with array exponent
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int power(int base, int exp) {
        int res = 1;
        base %= 1337;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % 1337;
            base = (base * base) % 1337;
            exp >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int lastDigit = b.back();
        b.pop_back();
        return power(superPow(a, b), 10) * power(a, lastDigit) % 1337;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> b = {3}; int res = s.superPow(2, b);

    cout << "Passed test for Super Pow" << endl;
    return 0;
}
