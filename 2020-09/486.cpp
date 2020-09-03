class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // 动态规划
        // dp[i][j] 表示玩家 1 在 i 到 j 范围内取得的最大分数差
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    continue;
                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }
        
        return dp[0][n - 1] >= 0;
    }
};