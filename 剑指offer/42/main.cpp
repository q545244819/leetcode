class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 动态规划
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));

        // 初始化
        // 用于处理只有一个元素的情况
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        // 状态转移方程：
        // dp[i][0] 表示从 0 到 i，且选择 i 后的最大值
        // nums[i] 表示只选择当前这个数，nums[i] + dp[i - 1][0] 表示选择当前数和 i - 1 的最大值相加，取两者较大的一个
        // dp[i][0] = max(nums[i], nums[i] + dp[i - 1][0])
        // dp[i][1] 表示从 0 到 i，且不选择 i 后到最大值
        // 从 i - 1 的选择和不选择比较，选择较大的一个
        // dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(nums[i], nums[i] + dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};