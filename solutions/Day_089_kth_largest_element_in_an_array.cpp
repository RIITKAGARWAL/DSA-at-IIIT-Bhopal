/**
 * Problem: Kth Largest Element in an Array
 * Day: 89 / 288
 * Category: Heap
 * Approach: Min-heap for Kth largest
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4}; int res = s.findKthLargest(nums, 2);

    cout << "Passed test for Kth Largest Element in an Array" << endl;
    return 0;
}
