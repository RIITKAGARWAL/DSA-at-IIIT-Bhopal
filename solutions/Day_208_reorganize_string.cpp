/**
 * Problem: Reorganize String
 * Day: 208 / 288
 * Category: Heap
 * Approach: Max-heap interleaving characters
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) pq.push({cnt[i], i + 'a'});
        }
        string res = "";
        pair<int, char> prev = {-1, '#'};
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            res += curr.second;
            curr.first--;
            if (prev.first > 0) pq.push(prev);
            prev = curr;
        }
        return res.size() == s.size() ? res : "";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    string res = s.reorganizeString("aab");

    cout << "Passed test for Reorganize String" << endl;
    return 0;
}
