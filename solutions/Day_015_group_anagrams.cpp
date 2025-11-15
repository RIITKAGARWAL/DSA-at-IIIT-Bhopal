/**
 * Problem: Group Anagrams
 * Day: 15 / 288
 * Category: Strings
 * Approach: Sorted string signature mapping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& pair : mp) res.push_back(pair.second);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"}; auto res = s.groupAnagrams(strs);

    cout << "Passed test for Group Anagrams" << endl;
    return 0;
}
