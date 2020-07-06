class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;

        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i - 1 >= 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j - 1 >= 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};