/**
 * Problem: Water and Jug Problem
 * Day: 249 / 288
 * Category: Math
 * Approach: Bézout's identity GCD check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity) return true;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool res = s.canMeasureWater(3, 5, 4);

    cout << "Passed test for Water and Jug Problem" << endl;
    return 0;
}
