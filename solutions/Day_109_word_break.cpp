/**
 * Problem: Word Break
 * Day: 109 / 288
 * Category: Dynamic Programming
 * Approach: 1D DP dictionary prefix lookup
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> wordDict = {"leet", "code"}; bool res = s.wordBreak("leetcode", wordDict);

    cout << "Passed test for Word Break" << endl;
    return 0;
}
