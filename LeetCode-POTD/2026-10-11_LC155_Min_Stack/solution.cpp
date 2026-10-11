#include <stack>
using namespace std;
class MinStack {
    stack<long long> st;
    long long minVal;
public:
    MinStack() {}
    void push(int val) {
        if (st.empty()) {
            st.push(0);
            minVal = val;
        } else {
            st.push((long long)val - minVal);
            if (val < minVal) minVal = val;
        }
    }
    void pop() {
        long long diff = st.top(); st.pop();
        if (diff < 0) minVal = minVal - diff;
    }
    int top() {
        long long diff = st.top();
        return diff < 0 ? minVal : minVal + diff;
    }
    int getMin() { return minVal; }
};