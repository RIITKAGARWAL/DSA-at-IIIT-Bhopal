#include <string>
using namespace std;
class Solution {
    bool isPalin(const string& s, int l, int r) {
        while (l < r) { if (s[l++] != s[r--]) return false; }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalin(s, i, j) && (j - i + 1) > maxLen) {
                    start = i; maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};