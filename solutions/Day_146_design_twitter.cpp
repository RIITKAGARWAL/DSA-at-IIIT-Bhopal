/**
 * Problem: Design Twitter
 * Day: 146 / 288
 * Category: Design
 * Approach: Max-heap feed aggregation with sets
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Twitter {
    long long time = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<long long, int>>> tweets;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<long long, int>> maxHeap;
        following[userId].insert(userId);
        for (int followeeId : following[userId]) {
            for (auto& t : tweets[followeeId]) maxHeap.push(t);
        }
        vector<int> res;
        for (int i = 0; i < 10 && !maxHeap.empty(); ++i) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
class Solution {
public:
    void testTwitter() {
        Twitter t; t.postTweet(1, 5); t.getNewsFeed(1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.testTwitter();

    cout << "Passed test for Design Twitter" << endl;
    return 0;
}
