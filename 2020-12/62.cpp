class Solution {
public:
    int uniquePaths(int m, int n) {
        // 思路：动态规划
        // dp[i][j] 表示从(0,0)走到(i,j)一共有多少条不同路径数量
        // base case: 第 0 行的所有列都为 1（因为一直往右走，只存在一条路径）
        // base case2: 第 0 列的所有行都为 1（因为一直往下走，只存在一条路径）
        // 状态转移方程：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        // 优化：滚动数组优化空间复杂度
        if (m == 0 && n == 0)
            return 0;
        if (m == 0 || n == 0)
            return 1;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

        return dp[m - 1][n - 1];
    }
};