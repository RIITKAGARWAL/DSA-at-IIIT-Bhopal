/**
 * Problem: Gas Station
 * Day: 123 / 288
 * Category: Greedy
 * Approach: Running surplus and start index tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currTank = 0, startStation = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if (currTank < 0) {
                startStation = i + 1;
                currTank = 0;
            }
        }
        return totalTank >= 0 ? startStation : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2}; int res = s.canCompleteCircuit(gas, cost);

    cout << "Passed test for Gas Station" << endl;
    return 0;
}
