/**
 * Problem: Add Two Numbers
 * Day: 54 / 288
 * Category: Linked List
 * Approach: Digit by digit addition with carry
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); ListNode* tail = &dummy; int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            tail->next = new ListNode(sum % 10);
            carry = sum / 10;
            tail = tail->next;
        }
        return dummy.next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode l1(2), l2(5); auto res = s.addTwoNumbers(&l1, &l2);

    cout << "Passed test for Add Two Numbers" << endl;
    return 0;
}
