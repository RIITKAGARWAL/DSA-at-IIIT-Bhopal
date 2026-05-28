/**
 * Problem: Minimum Cost to Hire K Workers
 * Day: 209 / 288
 * Category: Heap
 * Approach: Ratio sorting with Max-heap filter
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double res = DBL_MAX, qsum = 0;
        for (auto& w : workers) {
            qsum += w.second;
            pq.push(w.second);
            if (pq.size() > k) {
                qsum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                res = min(res, qsum * w.first);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> q = {10, 20, 5}, w = {70, 50, 30}; double res = s.mincostToHireWorkers(q, w, 2);

    cout << "Passed test for Minimum Cost to Hire K Workers" << endl;
    return 0;
}
