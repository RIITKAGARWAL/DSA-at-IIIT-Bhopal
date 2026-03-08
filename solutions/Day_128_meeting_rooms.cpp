/**
 * Problem: Meeting Rooms
 * Day: 128 / 288
 * Category: Intervals
 * Approach: Sort by start time and check overlap
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}}; bool res = s.canAttendMeetings(intervals);

    cout << "Passed test for Meeting Rooms" << endl;
    return 0;
}
