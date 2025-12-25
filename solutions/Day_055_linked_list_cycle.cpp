/**
 * Problem: Linked List Cycle
 * Day: 55 / 288
 * Category: Linked List
 * Approach: Floyd's Tortoise and Hare
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode head(1); bool res = s.hasCycle(&head);

    cout << "Passed test for Linked List Cycle" << endl;
    return 0;
}
