/**
 * Problem: Meeting Rooms II
 * Day: 129 / 288
 * Category: Intervals
 * Approach: Sort start and end arrays
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (const auto& inv : intervals) {
            starts.push_back(inv[0]);
            ends.push_back(inv[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int rooms = 0, maxRooms = 0, sPtr = 0, ePtr = 0;
        while (sPtr < intervals.size()) {
            if (starts[sPtr] < ends[ePtr]) {
                rooms++;
                sPtr++;
            } else {
                rooms--;
                ePtr++;
            }
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}}; int res = s.minMeetingRooms(intervals);

    cout << "Passed test for Meeting Rooms II" << endl;
    return 0;
}
