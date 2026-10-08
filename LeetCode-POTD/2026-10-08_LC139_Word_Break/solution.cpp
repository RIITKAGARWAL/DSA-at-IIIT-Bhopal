#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    bool solve(int start, const string& s, const unordered_set<string>& dict) {
        if (start == s.size()) return true;
        for (int end = start + 1; end <= s.size(); ++end) {
            if (dict.count(s.substr(start, end - start)) && solve(end, s, dict)) return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(0, s, dict);
    }
};