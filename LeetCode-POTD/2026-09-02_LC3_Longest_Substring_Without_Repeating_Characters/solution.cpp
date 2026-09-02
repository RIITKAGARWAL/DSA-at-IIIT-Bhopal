#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);
        int maxLen = 0, left = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (lastIndex[(unsigned char)s[right]] >= left) {
                left = lastIndex[(unsigned char)s[right]] + 1;
            }
            lastIndex[(unsigned char)s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};