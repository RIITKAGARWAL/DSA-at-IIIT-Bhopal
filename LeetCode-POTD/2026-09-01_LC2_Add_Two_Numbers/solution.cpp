struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};