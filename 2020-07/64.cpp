class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        // grid[i][j] 表示从(i-1, j)或(i, j - 1)到(i, j)的最少代价
        // 状态转移方程：grid[i][j] = min(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j])

        // 单独处理第一行
        for (int i = 1; i < m; i++)
            grid[0][i] += grid[0][i - 1];
        // 单独处理第一列
        for (int i = 1; i < n; i++)
            grid[i][0] += grid[i - 1][0];
        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                grid[i][j] = min(grid[i - 1][j] + grid[i][j], grid[i][j - 1] + grid[i][j]);

        return grid[n - 1][m - 1];
    }
};