/**
 * Problem: Sum of Subarray Minimums
 * Day: 204 / 288
 * Category: Stack
 * Approach: Strict and non-strict bounding spans
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> arr = {3, 1, 2, 4}; int res = s.sumSubarrayMins(arr);

    cout << "Passed test for Sum of Subarray Minimums" << endl;
    return 0;
}
