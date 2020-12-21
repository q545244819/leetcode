class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    // 思路：动态规划
    // dp[i] 表示走到第 i 个阶段的最小花费
    // 注意，需要在 cost 数组后新增一个元素 0，表示顶楼
    // base case: dp[0] = cost[0], dp[1] = cost[1]
    // dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
    int n = cost.size();

    if (n == 0)
      return 0;
    if (n == 1)
      return cost[0];

    vector<int> dp(n + 1, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    cost.push_back(0);

    for (int i = 2; i <= n; i++)
      dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];

    return dp[n];
  }
};