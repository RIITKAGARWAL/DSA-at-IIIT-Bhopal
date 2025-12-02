/**
 * Problem: Min Stack
 * Day: 32 / 288
 * Category: Stack
 * Approach: Auxiliary min value tracking
 * Author: SahityaJiya <sahityajiya1523@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    MinStack ms; ms.push(-2); ms.push(0); ms.push(-3); int m = ms.getMin();

    cout << "Passed test for Min Stack" << endl;
    return 0;
}
