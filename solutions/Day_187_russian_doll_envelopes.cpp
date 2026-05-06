/**
 * Problem: Russian Doll Envelopes
 * Day: 187 / 288
 * Category: Dynamic Programming
 * Approach: Sort + LIS Binary Search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        for (auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) dp.push_back(h);
            else *it = h;
        }
        return dp.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> envs = {{5,4},{6,4},{6,7},{2,3}}; int res = s.maxEnvelopes(envs);

    cout << "Passed test for Russian Doll Envelopes" << endl;
    return 0;
}
