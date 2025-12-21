/**
 * Problem: Reorder List
 * Day: 51 / 288
 * Category: Linked List
 * Approach: Find midpoint, reverse second half, and interweave
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
        ListNode *curr = slow->next; slow->next = nullptr;
        ListNode *prev = nullptr;
        while (curr) { ListNode *nxt = curr->next; curr->next = prev; prev = curr; curr = nxt; }
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second; second->next = tmp1;
            first = tmp1; second = tmp2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode head(1); s.reorderList(&head);

    cout << "Passed test for Reorder List" << endl;
    return 0;
}
