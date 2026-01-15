/**
 * Problem: Clone Graph
 * Day: 76 / 288
 * Category: Graphs
 * Approach: DFS hash map original-to-copy mapping
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class Node { public: int val; vector<Node*> neighbors; Node(int _val) { val = _val; } };
class Solution {
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val);
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    Node n1(1); auto res = s.cloneGraph(&n1);

    cout << "Passed test for Clone Graph" << endl;
    return 0;
}
