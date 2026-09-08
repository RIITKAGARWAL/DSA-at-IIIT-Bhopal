#include <vector>
#include <algorithm>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        for (auto l : lists) {
            while (l) { vals.push_back(l->val); l = l->next; }
        }
        sort(vals.begin(), vals.end());
        ListNode dummy(0);
        ListNode* curr = &dummy;
        for (int v : vals) {
            curr->next = new ListNode(v);
            curr = curr->next;
        }
        return dummy.next;
    }
};