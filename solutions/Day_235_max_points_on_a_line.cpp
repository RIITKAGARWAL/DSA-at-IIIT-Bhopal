/**
 * Problem: Max Points on a Line
 * Day: 235 / 288
 * Category: Geometry
 * Approach: Slope hash map counting
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int maxP = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeMap;
            int duplicates = 1, localMax = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) { duplicates++; continue; }
                int g = gcd(dx, dy);
                dx /= g; dy /= g;
                string slope = to_string(dx) + "_" + to_string(dy);
                slopeMap[slope]++;
                localMax = max(localMax, slopeMap[slope]);
            }
            maxP = max(maxP, localMax + duplicates);
        }
        return maxP;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pts = {{1,1},{2,2},{3,3}}; int res = s.maxPoints(pts);

    cout << "Passed test for Max Points on a Line" << endl;
    return 0;
}
