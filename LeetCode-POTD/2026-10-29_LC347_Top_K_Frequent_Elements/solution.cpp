#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [val, freq] : count) buckets[freq].push_back(val);
        vector<int> res;
        for (int i = nums.size(); i >= 0 && res.size() < k; --i) {
            for (int val : buckets[i]) {
                res.push_back(val);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};