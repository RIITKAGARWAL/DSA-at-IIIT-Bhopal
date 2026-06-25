/**
 * Problem: Minimum Area Rectangle
 * Day: 237 / 288
 * Category: Geometry
 * Approach: Diagonal point hash set lookup
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<string> pointSet;
        for (auto& p : points) pointSet.insert(to_string(p[0]) + "_" + to_string(p[1]));
        int minArea = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2 && y1 != y2) {
                    if (pointSet.count(to_string(x1) + "_" + to_string(y2)) &&
                        pointSet.count(to_string(x2) + "_" + to_string(y1))) {
                        minArea = min(minArea, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pts = {{1,1},{1,3},{3,1},{3,3},{2,2}}; int res = s.minAreaRect(pts);

    cout << "Passed test for Minimum Area Rectangle" << endl;
    return 0;
}
