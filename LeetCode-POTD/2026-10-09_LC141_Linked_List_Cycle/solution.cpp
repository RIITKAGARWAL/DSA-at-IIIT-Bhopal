#include <unordered_set>
using namespace std;
struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {} };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head) {
            if (visited.count(head)) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};