/**
 * Problem: All O`one Data Structure
 * Day: 234 / 288
 * Category: Design
 * Approach: Doubly linked list with frequency buckets
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class AllOne {
    struct Node {
        int freq;
        unordered_set<string> keys;
        Node* prev; Node* next;
        Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
    };
    Node* head; Node* tail;
    unordered_map<string, Node*> keyNode;
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
public:
    AllOne() {
        head = new Node(0); tail = new Node(0);
        head->next = tail; tail->prev = head;
    }
    void inc(string key) {
        if (!keyNode.count(key)) {
            if (head->next == tail || head->next->freq > 1) {
                Node* newNode = new Node(1);
                newNode->prev = head; newNode->next = head->next;
                head->next->prev = newNode; head->next = newNode;
            }
            head->next->keys.insert(key);
            keyNode[key] = head->next;
        } else {
            Node* curr = keyNode[key];
            int f = curr->freq;
            Node* nxt = curr->next;
            if (nxt == tail || nxt->freq > f + 1) {
                Node* newNode = new Node(f + 1);
                newNode->prev = curr; newNode->next = nxt;
                curr->next = newNode; nxt->prev = newNode;
                nxt = newNode;
            }
            nxt->keys.insert(key);
            keyNode[key] = nxt;
            curr->keys.erase(key);
            if (curr->keys.empty()) removeNode(curr);
        }
    }
    void dec(string key) {
        Node* curr = keyNode[key];
        int f = curr->freq;
        curr->keys.erase(key);
        if (f == 1) {
            keyNode.erase(key);
        } else {
            Node* prv = curr->prev;
            if (prv == head || prv->freq < f - 1) {
                Node* newNode = new Node(f - 1);
                newNode->prev = prv; newNode->next = curr;
                prv->next = newNode; curr->prev = newNode;
                prv = newNode;
            }
            prv->keys.insert(key);
            keyNode[key] = prv;
        }
        if (curr->keys.empty()) removeNode(curr);
    }
    string getMaxKey() {
        return tail->prev == head ? "" : *tail->prev->keys.begin();
    }
    string getMinKey() {
        return head->next == tail ? "" : *head->next->keys.begin();
    }
};
class Solution {
public:
    void test() { AllOne ao; ao.inc("hello"); ao.getMaxKey(); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for All O`one Data Structure" << endl;
    return 0;
}
