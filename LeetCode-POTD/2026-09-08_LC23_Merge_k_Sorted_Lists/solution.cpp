#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto l : lists) { if (l) pq.push(l); }
        ListNode dummy(0);
        ListNode* curr = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};