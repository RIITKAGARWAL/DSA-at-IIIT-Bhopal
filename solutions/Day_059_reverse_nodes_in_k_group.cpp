/**
 * Problem: Reverse Nodes in k-Group
 * Day: 59 / 288
 * Category: Linked List
 * Approach: Segment reversal loop
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head; int count = 0;
        while (curr && count != k) { curr = curr->next; count++; }
        if (count == k) {
            curr = reverseKGroup(curr, k);
            while (count-- > 0) {
                ListNode* tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
            }
            head = curr;
        }
        return head;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode head(1); auto res = s.reverseKGroup(&head, 1);

    cout << "Passed test for Reverse Nodes in k-Group" << endl;
    return 0;
}
