class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(m));

        // dp[i][j] 表示在到(i, j)位置上至少需要“最低初始健康点数”
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1)
                    dp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
                else if (i == n - 1)
                    dp[i][j] = max(1, dp[n - 1][j + 1] - dungeon[i][j]);
                else if (j == m - 1)
                    dp[i][j] = max(1, dp[i + 1][m - 1] - dungeon[i][j]);
                else
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};