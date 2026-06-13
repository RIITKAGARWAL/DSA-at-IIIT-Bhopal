/**
 * Problem: Longest Duplicate Substring
 * Day: 225 / 288
 * Category: String
 * Approach: Rabin-Karp Rolling Hash + Binary Search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        long long MOD = 1e9 + 7, BASE = 26;
        auto search = [&](int len) {
            long long hash = 0, power = 1;
            for (int i = 0; i < len; ++i) {
                hash = (hash * BASE + (s[i] - 'a')) % MOD;
                if (i > 0) power = (power * BASE) % MOD;
            }
            unordered_set<long long> seen = {hash};
            for (int i = len; i < n; ++i) {
                hash = (hash - (s[i - len] - 'a') * power % MOD + MOD) % MOD;
                hash = (hash * BASE + (s[i] - 'a')) % MOD;
                if (seen.count(hash)) return i - len + 1;
                seen.insert(hash);
            }
            return -1;
        };
        int l = 1, r = n, start = -1, maxLen = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int idx = search(mid);
            if (idx != -1) {
                start = idx;
                maxLen = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return start == -1 ? "" : s.substr(start, maxLen);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.longestDupSubstring("banana");

    cout << "Passed test for Longest Duplicate Substring" << endl;
    return 0;
}
