/**
 * Problem: Line Reflection
 * Day: 236 / 288
 * Category: Geometry
 * Approach: X-coordinate midpoint reflection check
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        unordered_set<string> set;
        int minX = INT_MAX, maxX = INT_MIN;
        for (auto& p : points) {
            minX = min(minX, p[0]);
            maxX = max(maxX, p[0]);
            set.insert(to_string(p[0]) + "_" + to_string(p[1]));
        }
        int sum = minX + maxX;
        for (auto& p : points) {
            string reflected = to_string(sum - p[0]) + "_" + to_string(p[1]);
            if (!set.count(reflected)) return false;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pts = {{1,1},{-1,1}}; bool res = s.isReflected(pts);

    cout << "Passed test for Line Reflection" << endl;
    return 0;
}
