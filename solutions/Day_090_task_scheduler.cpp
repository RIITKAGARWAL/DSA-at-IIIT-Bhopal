/**
 * Problem: Task Scheduler
 * Day: 90 / 288
 * Category: Greedy
 * Approach: Max frequency math formula
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        int maxFreq = 0, maxCount = 0;
        for (char task : tasks) {
            counts[task - 'A']++;
            if (counts[task - 'A'] > maxFreq) {
                maxFreq = counts[task - 'A'];
                maxCount = 1;
            } else if (counts[task - 'A'] == maxFreq) {
                maxCount++;
            }
        }
        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxFreq * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        return tasks.size() + idles;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'}; int res = s.leastInterval(tasks, 2);

    cout << "Passed test for Task Scheduler" << endl;
    return 0;
}
