#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto& iv : intervals) {
            if (merged.empty() || merged.back()[1] < iv[0]) merged.push_back(iv);
            else merged.back()[1] = max(merged.back()[1], iv[1]);
        }
        return merged;
    }
};