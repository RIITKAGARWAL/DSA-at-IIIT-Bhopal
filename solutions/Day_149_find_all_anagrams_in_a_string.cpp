/**
 * Problem: Find All Anagrams in a String
 * Day: 149 / 288
 * Category: Sliding Window
 * Approach: Fixed-size frequency window array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> pCount(26, 0), sCount(26, 0), res;
        for (int i = 0; i < p.size(); ++i) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        if (pCount == sCount) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            sCount[s[i] - 'a']++;
            sCount[s[i - p.size()] - 'a']--;
            if (pCount == sCount) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    auto res = s.findAnagrams("cbaebabacd", "abc");

    cout << "Passed test for Find All Anagrams in a String" << endl;
    return 0;
}
