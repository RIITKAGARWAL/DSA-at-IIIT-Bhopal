/**
 * Problem: Merge k Sorted Lists
 * Day: 58 / 288
 * Category: Linked List
 * Approach: Min-heap priority queue
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
    struct compare { bool operator()(const ListNode* l, const ListNode* r) { return l->val > r->val; } };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto l : lists) if (l) pq.push(l);
        ListNode dummy(0); ListNode* tail = &dummy;
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return dummy.next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    vector<ListNode*> lists; auto res = s.mergeKLists(lists);

    cout << "Passed test for Merge k Sorted Lists" << endl;
    return 0;
}
