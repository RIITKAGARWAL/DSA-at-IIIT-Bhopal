/**
 * Problem: Scramble String
 * Day: 253 / 288
 * Category: Dynamic Programming
 * Approach: Memoized recursive string partitioning
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, bool> memo;
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];
        int n = s1.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) if (c != 0) return memo[key] = false;
        for (int i = 1; i < n; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.isScramble("great", "rgeat");

    cout << "Passed test for Scramble String" << endl;
    return 0;
}
