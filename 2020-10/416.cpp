class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 思路使用 01 背包判断是否能够从0～nums.size()里选择若干个数组成 sum(0, nums.size()) / 2;
        int n = nums.size();
        int sum = 0;

        for (int n : nums) sum += n;
        if (sum & 1) return false;
        int m = sum / 2;

        vector<bool> dp(m + 1, false);

        dp[0] = true;

        for (int i : nums) {
            for (int j = m; j >= i; j--) {
                dp[j] = dp[j] || dp[j - i];
            }
        }

        return dp[m];
    }
};