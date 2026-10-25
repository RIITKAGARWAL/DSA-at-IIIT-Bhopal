#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZero;
        for (int x : nums) { if (x != 0) nonZero.push_back(x); }
        for (size_t i = 0; i < nonZero.size(); ++i) nums[i] = nonZero[i];
        for (size_t i = nonZero.size(); i < nums.size(); ++i) nums[i] = 0;
    }
};