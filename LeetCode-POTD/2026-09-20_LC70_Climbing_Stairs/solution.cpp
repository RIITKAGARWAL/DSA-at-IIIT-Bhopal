class Solution {
    int helper(int n) {
        if (n <= 1) return 1;
        return helper(n - 1) + helper(n - 2);
    }
public:
    int climbStairs(int n) {
        return helper(n);
    }
};