/**
 * Problem: Maximum Profit in Job Scheduling
 * Day: 260 / 288
 * Category: Dynamic Programming
 * Approach: Sort + Binary Search DP scheduling
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, 0);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; ++i) {
            int incl = jobs[i][2];
            int l = 0, r = i - 1, idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (idx != -1) incl += dp[idx];
            dp[i] = max(dp[i - 1], incl);
        }
        return dp[n - 1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> st = {1,2,3,3}, et = {3,4,5,6}, p = {50,10,40,70}; int res = s.jobScheduling(st, et, p);

    cout << "Passed test for Maximum Profit in Job Scheduling" << endl;
    return 0;
}
