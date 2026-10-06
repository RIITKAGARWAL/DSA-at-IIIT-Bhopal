#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;
        for (int x : st) {
            if (!st.count(x - 1)) {
                int len = 1;
                while (st.count(x + len)) len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};