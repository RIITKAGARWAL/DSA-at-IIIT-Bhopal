/**
 * Problem: Time Based Key-Value Store
 * Day: 46 / 288
 * Category: Binary Search
 * Approach: Timestamped vector binary search
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        const auto& list = mp[key];
        int l = 0, r = list.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (list[mid].first <= timestamp) {
                res = list[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    TimeMap tm; tm.set("foo", "bar", 1); string res = tm.get("foo", 1);

    cout << "Passed test for Time Based Key-Value Store" << endl;
    return 0;
}
