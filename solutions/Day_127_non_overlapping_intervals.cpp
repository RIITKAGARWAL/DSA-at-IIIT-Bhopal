/**
 * Problem: Non-overlapping Intervals
 * Day: 127 / 288
 * Category: Intervals
 * Approach: Greedy sort by end time
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0, end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                count++;
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}}; int res = s.eraseOverlapIntervals(intervals);

    cout << "Passed test for Non-overlapping Intervals" << endl;
    return 0;
}
