#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_sum = 0;
        for (int x : nums) xor_sum ^= x;
        return xor_sum;
    }
};