/**
 * Problem: Car Fleet
 * Day: 35 / 288
 * Category: Stack
 * Approach: Arrival time monotonic grouping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double maxTime = 0.0;
        for (const auto& car : cars) {
            if (car.second > maxTime) {
                fleets++;
                maxTime = car.second;
            }
        }
        return fleets;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> pos = {10, 8, 0, 5, 3}; vector<int> spd = {2, 4, 1, 1, 3}; int res = s.carFleet(12, pos, spd);

    cout << "Passed test for Car Fleet" << endl;
    return 0;
}
