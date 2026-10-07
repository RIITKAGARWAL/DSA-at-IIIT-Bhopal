#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int x : nums) count[x]++;
        for (auto& [val, c] : count) {
            if (c == 1) return val;
        }
        return -1;
    }
};