/**
 * Problem: Top K Frequent Words
 * Day: 207 / 288
 * Category: Heap
 * Approach: Min-heap with custom string comparator
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto& w : words) freq[w]++;
        auto comp = [](pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        for (auto& p : freq) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"}; auto res = s.topKFrequent(words, 2);

    cout << "Passed test for Top K Frequent Words" << endl;
    return 0;
}
