class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
  {
    // 思路：动态规划
    // buy[i] 表示第 i 天买入时手里的最大利润
    // sell[i] 表示第 i 天卖出手里的最大利润
    // base case: buy[0] = -price[0], sell[0] = 0;
    // buy[i] = max(当天买入+上一天卖出最大利润，当天买入（之前未卖出）最大利润，上一天买入最大利润)
    // sell[i] = max(当天卖出+上一天买入最大利润，当天卖出（仅扣手续费）最大利润，上一天卖出最大利润)
    int n = prices.size();

    if (n == 0)
      return 0;

    vector<int> buy(n, 0);
    vector<int> sell(n, 0);

    buy[0] = -prices[0];
    sell[0] = 0;

    for (int i = 1; i < n; i++)
    {
      buy[i] = max(-prices[i] + sell[i - 1], max(-prices[i], buy[i - 1]));
      sell[i] = max(prices[i] + buy[i - 1] - fee, max(-fee, sell[i - 1]));
    }

    return max(buy[n - 1], sell[n - 1]);
  }
};