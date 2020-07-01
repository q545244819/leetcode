class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int ans = 0;

		// 动态规划
		// dp[i][j] 表示 a[0] ~ a[i] 和 b[0] ~ b[j] 的范围内最长的子数组长度
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) dp[i][j] += dp[i - 1][j - 1];
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};