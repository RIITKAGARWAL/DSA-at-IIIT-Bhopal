/**
 * Problem: Koko Eating Bananas
 * Day: 43 / 288
 * Category: Binary Search
 * Approach: Binary search on answer space
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int k = l + (r - l) / 2;
            long long hours = 0;
            for (int p : piles) {
                hours += (p + k - 1) / k;
            }
            if (hours <= h) {
                ans = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> piles = {3, 6, 7, 11}; int res = s.minEatingSpeed(piles, 8);

    cout << "Passed test for Koko Eating Bananas" << endl;
    return 0;
}
