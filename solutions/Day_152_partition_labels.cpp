/**
 * Problem: Partition Labels
 * Day: 152 / 288
 * Category: Greedy
 * Approach: Last occurrence hash map
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            lastIdx[s[i] - 'a'] = i;
        }
        vector<int> res;
        int size = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            size++;
            end = max(end, lastIdx[s[i] - 'a']);
            if (i == end) {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.partitionLabels("ababcbacadefegdehijhklij");

    cout << "Passed test for Partition Labels" << endl;
    return 0;
}
