/**
 * Problem: LFU Cache
 * Day: 232 / 288
 * Category: Design
 * Approach: Hash Map frequency buckets with doubly linked lists
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int cap, minFreq, size;
    struct Node {
        int key, val, freq;
        Node* prev; Node* next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };
    struct List {
        Node* head; Node* tail; int size;
        List() {
            head = new Node(0, 0); tail = new Node(0, 0);
            head->next = tail; tail->prev = head; size = 0;
        }
        void addNode(Node* node) {
            node->prev = head; node->next = head->next;
            head->next->prev = node; head->next = node; size++;
        }
        void removeNode(Node* node) {
            node->prev->next = node->next; node->next->prev = node->prev; size--;
        }
    };
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
public:
    LFUCache(int capacity) { cap = capacity; minFreq = 0; size = 0; }
    int get(int key) {
        if (!keyNode.count(key)) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }
    void put(int key, int value) {
        if (cap <= 0) return;
        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (size >= cap) {
                List* list = freqListMap[minFreq];
                Node* lru = list->tail->prev;
                keyNode.erase(lru->key);
                list->removeNode(lru);
                size--;
            }
            Node* node = new Node(key, value);
            minFreq = 1;
            if (!freqListMap.count(1)) freqListMap[1] = new List();
            freqListMap[1]->addNode(node);
            keyNode[key] = node;
            size++;
        }
    }
    void updateFreq(Node* node) {
        int f = node->freq;
        List* list = freqListMap[f];
        list->removeNode(node);
        if (f == minFreq && list->size == 0) minFreq++;
        node->freq++;
        if (!freqListMap.count(node->freq)) freqListMap[node->freq] = new List();
        freqListMap[node->freq]->addNode(node);
    }
};
class Solution {
public:
    void test() { LFUCache lfu(2); lfu.put(1, 1); lfu.get(1); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    s.test();

    cout << "Passed test for LFU Cache" << endl;
    return 0;
}
