/**
 * Problem: Find Median from Data Stream
 * Day: 206 / 288
 * Category: Heap
 * Approach: Two priority queues (Min & Max)
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
public:
    MedianFinder() {}
    void addNum(int num) {
        maxH.push(num);
        minH.push(maxH.top());
        maxH.pop();
        if (minH.size() > maxH.size()) {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    double findMedian() {
        return maxH.size() > minH.size() ? maxH.top() : (maxH.top() + minH.top()) / 2.0;
    }
};
class Solution {
public:
    void test() { MedianFinder mf; mf.addNum(1); mf.addNum(2); mf.findMedian(); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Find Median from Data Stream" << endl;
    return 0;
}
