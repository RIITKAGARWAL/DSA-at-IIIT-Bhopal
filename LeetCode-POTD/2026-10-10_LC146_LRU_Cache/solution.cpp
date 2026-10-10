#include <unordered_map>
using namespace std;
class LRUCache {
    struct Node {
        int k, v;
        Node *prev, *next;
        Node(int key, int val) : k(key), v(val), prev(nullptr), next(nullptr) {}
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0); tail = new Node(0, 0);
        head->next = tail; tail->prev = head;
    }
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        removeNode(node); addNode(node);
        return node->v;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->v = value;
            removeNode(node); addNode(node);
            return;
        }
        if (mp.size() == cap) {
            Node* del = tail->prev;
            mp.erase(del->k);
            removeNode(del);
            delete del;
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addNode(newNode);
    }
};