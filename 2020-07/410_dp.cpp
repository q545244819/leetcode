class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // dp[i][j] 划分从 0 ~ j 划分 i 组的最大值中的最小值
        // 注意 int 的范围
        int n = nums.size();
        vector<vector<long>> dp(m + 1, vector<long>(n, INT_MAX));
        // 前缀和
        vector<long> sums(n, 0);

        sums[0] = nums[0];
        for (int i = 1; i < n; i++)
            sums[i] = sums[i - 1] + nums[i];
        
        for (int i = 0; i < n; i++)
            dp[1][i] = sums[i];

        for (int i = 2; i <= m; i++)
            for (int j = i - 1; j < n; j++)
                for (int k = 0; k < j; k++)
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k]));

        return dp[m][n - 1];
    }
};