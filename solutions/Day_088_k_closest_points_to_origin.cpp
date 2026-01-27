/**
 * Problem: K Closest Points to Origin
 * Day: 88 / 288
 * Category: Heap
 * Approach: Max-heap sorted by distance
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto& p : points) {
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.push({dist, p});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> pts = {{1, 3}, {-2, 2}}; auto res = s.kClosest(pts, 1);

    cout << "Passed test for K Closest Points to Origin" << endl;
    return 0;
}
