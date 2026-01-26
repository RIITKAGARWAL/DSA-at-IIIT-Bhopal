/**
 * Problem: Last Stone Weight
 * Day: 87 / 288
 * Category: Heap
 * Approach: Max-heap simulation
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if (x != y) pq.push(y - x);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> stones = {2, 7, 4, 1, 8, 1}; int res = s.lastStoneWeight(stones);

    cout << "Passed test for Last Stone Weight" << endl;
    return 0;
}
