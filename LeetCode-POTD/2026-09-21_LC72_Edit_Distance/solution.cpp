#include <string>
#include <algorithm>
using namespace std;
class Solution {
    int solve(int i, int j, const string& w1, const string& w2) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (w1[i - 1] == w2[j - 1]) return solve(i - 1, j - 1, w1, w2);
        return 1 + min({solve(i - 1, j, w1, w2), solve(i, j - 1, w1, w2), solve(i - 1, j - 1, w1, w2)});
    }
public:
    int minDistance(string word1, string word2) {
        return solve(word1.size(), word2.size(), word1, word2);
    }
};