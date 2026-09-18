class Solution {
    int dfs(int r, int c, int m, int n) {
        if (r == m - 1 && c == n - 1) return 1;
        if (r >= m || c >= n) return 0;
        return dfs(r + 1, c, m, n) + dfs(r, c + 1, m, n);
    }
public:
    int uniquePaths(int m, int n) {
        return dfs(0, 0, m, n);
    }
};