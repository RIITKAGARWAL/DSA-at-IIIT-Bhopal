/**
 * Problem: Valid Anagram
 * Day: 14 / 288
 * Category: Strings
 * Approach: 26-length fixed frequency array
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {0};
        for (int i = 0; i < (int)s.size(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int x : count) if (x != 0) return false;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    bool res = s.isAnagram("anagram", "nagaram");

    cout << "Passed test for Valid Anagram" << endl;
    return 0;
}
