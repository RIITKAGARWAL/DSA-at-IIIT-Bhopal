/**
 * Problem: Remove Nth Node From End of List
 * Day: 52 / 288
 * Category: Linked List
 * Approach: Fast and slow pointer gap
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0); dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i <= n; ++i) fast = fast->next;
        while (fast) { fast = fast->next; slow = slow->next; }
        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode head(1); auto res = s.removeNthFromEnd(&head, 1);

    cout << "Passed test for Remove Nth Node From End of List" << endl;
    return 0;
}
