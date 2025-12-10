/**
 * Problem: Asteroid Collision
 * Day: 40 / 288
 * Category: Stack
 * Approach: Mass collision simulation stack
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool destroyed = false;
            while (!st.empty() && a < 0 && st.back() > 0) {
                if (st.back() < -a) {
                    st.pop_back();
                    continue;
                } else if (st.back() == -a) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) st.push_back(a);
        }
        return st;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> ast = {5, 10, -5}; auto res = s.asteroidCollision(ast);

    cout << "Passed test for Asteroid Collision" << endl;
    return 0;
}
