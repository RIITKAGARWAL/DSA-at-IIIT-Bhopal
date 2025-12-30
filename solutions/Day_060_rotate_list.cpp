/**
 * Problem: Rotate List
 * Day: 60 / 288
 * Category: Linked List
 * Approach: Ring formation and break
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 1; ListNode* tail = head;
        while (tail->next) { tail = tail->next; len++; }
        tail->next = head;
        k = k % len; int stepsToNewHead = len - k;
        while (stepsToNewHead--) tail = tail->next;
        ListNode* newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode head(1); auto res = s.rotateRight(&head, 1);

    cout << "Passed test for Rotate List" << endl;
    return 0;
}
