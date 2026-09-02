#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), maxLen = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<char> seen;
            for (int j = i; j < n; ++j) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};