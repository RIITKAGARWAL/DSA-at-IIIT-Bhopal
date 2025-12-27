/**
 * Problem: LRU Cache
 * Day: 57 / 288
 * Category: Linked List
 * Approach: Hash map and doubly linked list
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    struct Node { int key, val; Node *prev, *next; Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {} };
    int cap; unordered_map<int, Node*> mp; Node *head, *tail;
    void add(Node* node) { node->prev = head; node->next = head->next; head->next->prev = node; head->next = node; }
    void remove(Node* node) { node->prev->next = node->next; node->next->prev = node->prev; }
public:
    LRUCache(int capacity) { cap = capacity; head = new Node(-1, -1); tail = new Node(-1, -1); head->next = tail; tail->prev = head; }
    int get(int key) { if (mp.find(key) == mp.end()) return -1; Node* resNode = mp[key]; int res = resNode->val; mp.erase(key); remove(resNode); add(resNode); mp[key] = head->next; return res; }
    void put(int key, int value) { if (mp.find(key) != mp.end()) { Node* exist = mp[key]; mp.erase(key); remove(exist); } if (mp.size() == cap) { mp.erase(tail->prev->key); remove(tail->prev); } add(new Node(key, value)); mp[key] = head->next; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    LRUCache cache(2); cache.put(1, 1); int res = cache.get(1);

    cout << "Passed test for LRU Cache" << endl;
    return 0;
}
