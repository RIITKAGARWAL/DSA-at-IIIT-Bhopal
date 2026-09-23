#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        for (char c : t) tmap[c]++;
        int n = s.size(), minLen = 1e9, start = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> smap;
            for (int j = i; j < n; ++j) {
                smap[s[j]]++;
                bool ok = true;
                for (auto& [c, count] : tmap) {
                    if (smap[c] < count) { ok = false; break; }
                }
                if (ok && (j - i + 1) < minLen) {
                    minLen = j - i + 1;
                    start = i;
                    break;
                }
            }
        }
        return minLen == 1e9 ? "" : s.substr(start, minLen);
    }
};