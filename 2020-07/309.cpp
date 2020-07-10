class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
          题解来自评论区：@marsh
          sell[i]表示截至第i天，最后一个操作是卖时的最大收益；
          buy[i]表示截至第i天，最后一个操作是买时的最大收益；
          cool[i]表示截至第i天，最后一个操作是冷冻期时的最大收益；
          递推公式：
          sell[i] = max(buy[i-1]+prices[i], sell[i-1]) (第一项表示第i天卖出，第二项表示第i天冷冻)
          buy[i] = max(cool[i-1]-prices[i], buy[i-1]) （第一项表示第i天买进，第二项表示第i天冷冻）
          cool[i] = max(sell[i-1], buy[i-1], cool[i-1])
        */
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return dp[n - 1][0];
    }
};