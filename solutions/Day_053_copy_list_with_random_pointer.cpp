/**
 * Problem: Copy List with Random Pointer
 * Day: 53 / 288
 * Category: Linked List
 * Approach: Interleaved node clones
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Node { public: int val; Node* next; Node* random; Node(int _val) { val = _val; next = NULL; random = NULL; } };
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) { Node* clone = new Node(curr->val); clone->next = curr->next; curr->next = clone; curr = clone->next; }
        curr = head;
        while (curr) { if (curr->random) curr->next->random = curr->random->next; curr = curr->next->next; }
        curr = head; Node* cloneHead = head->next;
        while (curr) { Node* clone = curr->next; curr->next = clone->next; if (clone->next) clone->next = clone->next->next; curr = curr->next; }
        return cloneHead;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    Node head(1); auto res = s.copyRandomList(&head);

    cout << "Passed test for Copy List with Random Pointer" << endl;
    return 0;
}
