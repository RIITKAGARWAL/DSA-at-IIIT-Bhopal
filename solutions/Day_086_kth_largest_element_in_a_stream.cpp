/**
 * Problem: Kth Largest Element in a Stream
 * Day: 86 / 288
 * Category: Heap
 * Approach: Min-heap of size K
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) add(num);
    }
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
class Solution {
public:
    void testKth() {
        vector<int> nums = {4, 5, 8, 2}; KthLargest kth(3, nums); kth.add(3);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.testKth();

    cout << "Passed test for Kth Largest Element in a Stream" << endl;
    return 0;
}
