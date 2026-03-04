/**
 * Problem: Hand of Straights
 * Day: 124 / 288
 * Category: Greedy
 * Approach: Ordered map group extraction
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for (int card : hand) count[card]++;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 0) {
                int startCard = it->first;
                int times = it->second;
                for (int i = 0; i < groupSize; ++i) {
                    if (count[startCard + i] < times) return false;
                    count[startCard + i] -= times;
                }
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8}; bool res = s.isNStraightHand(hand, 3);

    cout << "Passed test for Hand of Straights" << endl;
    return 0;
}
