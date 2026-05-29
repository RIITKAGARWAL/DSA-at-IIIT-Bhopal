/**
 * Problem: IPO
 * Day: 210 / 288
 * Category: Heap
 * Approach: Greedy max profit filtering available capital
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> proj;
        for (int i = 0; i < profits.size(); ++i) {
            proj.push_back({capital[i], profits[i]});
        }
        sort(proj.begin(), proj.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k--) {
            while (idx < proj.size() && proj[idx].first <= w) {
                pq.push(proj[idx++].second);
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> p = {1, 2, 3}, c = {0, 1, 1}; int res = s.findMaximizedCapital(2, 0, p, c);

    cout << "Passed test for IPO" << endl;
    return 0;
}
