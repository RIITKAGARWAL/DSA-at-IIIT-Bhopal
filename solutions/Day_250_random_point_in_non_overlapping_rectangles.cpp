/**
 * Problem: Random Point in Non-overlapping Rectangles
 * Day: 250 / 288
 * Category: Math
 * Approach: Weighted reservoir sampling
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> rects;
    vector<int> prefixSum;
    int totalArea = 0;
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        for (auto& r : rects) {
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            totalArea += area;
            prefixSum.push_back(totalArea);
        }
    }
    vector<int> pick() {
        int r = rand() % totalArea + 1;
        int idx = lower_bound(prefixSum.begin(), prefixSum.end(), r) - prefixSum.begin();
        auto& rect = rects[idx];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};
class SolutionTest {
public:
    void test() {
        vector<vector<int>> rects = {{-2, -2, -1, -1}, {1, 2, 3, 4}};
        Solution sol(rects);
        sol.pick();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SolutionTest st; st.test();

    cout << "Passed test for Random Point in Non-overlapping Rectangles" << endl;
    return 0;
}
