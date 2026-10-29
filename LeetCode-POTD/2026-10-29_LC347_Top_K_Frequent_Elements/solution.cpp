#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        vector<pair<int, int>> p(mp.begin(), mp.end());
        sort(p.begin(), p.end(), [](auto& a, auto& b) { return a.second > b.second; });
        vector<int> res;
        for (int i = 0; i < k; ++i) res.push_back(p[i].first);
        return res;
    }
};