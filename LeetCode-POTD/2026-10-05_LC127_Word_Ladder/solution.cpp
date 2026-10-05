#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        unordered_set<string> set1{beginWord}, set2{endWord};
        int step = 1;
        while (!set1.empty() && !set2.empty()) {
            if (set1.size() > set2.size()) swap(set1, set2);
            unordered_set<string> nextSet;
            for (string word : set1) {
                for (int i = 0; i < word.size(); ++i) {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (set2.count(word)) return step + 1;
                        if (dict.count(word)) {
                            dict.erase(word);
                            nextSet.insert(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            set1 = nextSet;
            step++;
        }
        return 0;
    }
};