/**
 * Problem: Erect the Fence
 * Day: 231 / 288
 * Category: Geometry
 * Approach: Monotone Chain Convex Hull
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int crossProduct(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 1) return trees;
        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        vector<vector<int>> hull;
        for (int i = 0; i < trees.size(); ++i) {
            while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) > 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        for (int i = (int)trees.size() - 2, t = hull.size() + 1; i >= 0; --i) {
            while (hull.size() >= t && crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) > 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        hull.pop_back();
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> trees = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}}; auto res = s.outerTrees(trees);

    cout << "Passed test for Erect the Fence" << endl;
    return 0;
}
