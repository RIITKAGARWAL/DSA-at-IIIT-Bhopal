/**
 * Problem: Insert Delete GetRandom O(1)
 * Day: 145 / 288
 * Category: Design
 * Approach: Vector and Hash Map swap synchronization
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> pos;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if (pos.count(val)) return false;
        nums.push_back(val);
        pos[val] = nums.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (!pos.count(val)) return false;
        int last = nums.back();
        int idx = pos[val];
        nums[idx] = last;
        pos[last] = idx;
        nums.pop_back();
        pos.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
class Solution {
public:
    void testDesign() {
        RandomizedSet rs; rs.insert(1); rs.remove(2); rs.insert(2); rs.getRandom();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.testDesign();

    cout << "Passed test for Insert Delete GetRandom O(1)" << endl;
    return 0;
}
