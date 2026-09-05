#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> t = {nums[i], nums[j], nums[k]};
                        sort(t.begin(), t.end());
                        st.insert(t);
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};