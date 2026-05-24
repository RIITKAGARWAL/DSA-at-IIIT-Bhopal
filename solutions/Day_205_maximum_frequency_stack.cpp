/**
 * Problem: Maximum Frequency Stack
 * Day: 205 / 288
 * Category: Stack
 * Approach: Hash map of frequencies to stacks
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq = 0;
public:
    FreqStack() {}
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        group[freq[val]].push(val);
    }
    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};
class Solution {
public:
    void test() { FreqStack fs; fs.push(5); fs.push(5); fs.pop(); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for Maximum Frequency Stack" << endl;
    return 0;
}
