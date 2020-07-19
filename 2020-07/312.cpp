class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> data(n);
        vector<vector<int>> dp(n, vector<int>(n, 0));

        data[0] = data[n - 1] = 1;
        for (int i = 1; i < n - 1; i++)
            data[i] = nums[i - 1];

        // 区间动态规划模版
        for (int len = 2; len < n; len++) {
            for (int l = 0; l < n - len; l++) {
                int r = l + len;

                for (int k = l + 1; k < r; k++)
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + data[k] * data[l] * data[r]);
            }
        }

        return dp[0][n - 1];
    }
};