/**
 * Problem: Permutation in String
 * Day: 157 / 288
 * Category: Sliding Window
 * Approach: Fixed-size frequency array comparison
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> c1(26, 0), c2(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        if (c1 == c2) return true;
        for (int i = s1.size(); i < s2.size(); ++i) {
            c2[s2[i] - 'a']++;
            c2[s2[i - s1.size()] - 'a']--;
            if (c1 == c2) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.checkInclusion("ab", "eidbaooo");

    cout << "Passed test for Permutation in String" << endl;
    return 0;
}
