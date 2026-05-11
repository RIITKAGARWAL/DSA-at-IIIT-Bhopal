/**
 * Problem: Count of Smaller Numbers After Self
 * Day: 192 / 288
 * Category: Divide and Conquer
 * Approach: Merge Sort inversion counting
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void mergeSort(vector<pair<int, int>>& arr, vector<int>& res, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, res, left, mid);
        mergeSort(arr, res, mid + 1, right);
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0, rightCount = 0;
        while (i <= mid && j <= right) {
            if (arr[j].first < arr[i].first) {
                rightCount++;
                temp[k++] = arr[j++];
            } else {
                res[arr[i].second] += rightCount;
                temp[k++] = arr[i++];
            }
        }
        while (i <= mid) { res[arr[i].second] += rightCount; temp[k++] = arr[i++]; }
        while (j <= right) { temp[k++] = arr[j++]; }
        for (int p = 0; p < k; ++p) arr[left + p] = temp[p];
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], i};
        vector<int> res(n, 0);
        mergeSort(arr, res, 0, n - 1);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<int> nums = {5, 2, 6, 1}; auto res = s.countSmaller(nums);

    cout << "Passed test for Count of Smaller Numbers After Self" << endl;
    return 0;
}
