class Solution {
public:
    int minimumOperations(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(3, n));
        // 可以优化空间为O（1）
        // 子问题可以从只构建只有 r 的字符串开始
        // 若需要构建排列为 ry 的字符串，则可以从只有 r 的字符串或者 ry 排列的字符串构建，通过末尾添加 y
        // 若需要构建排列为 ryr 的字符串，则可以从 ry 排列的字符串和 ryr 排列的字符串构建，通过末尾添加 r
        // 所以得出了三种状态，分别是排列 r，排列 ry 和排列 ryr

        dp[0][0] = s[0] == 'r' ? 0 : 1;
        // dp[i][j] 表示从 0 到 i，替换满足 j 排列的最小次数
        // j = 0 表示交换成排列 r 需要的最少次数
        // j = 1 表示交换成排列 ry 需要的最少次数
        // j = 2 表示交换成排列 ryr 需要的最少次数

        for (int i = 1; i < n; i++) {
            // 每一种排列情况中，若最后一个字符不符合排列的要求，则数量需要加 1
            // 只能从 r 这一种交换次数扩展，取需要交换次数最少的
            dp[i][0] = dp[i - 1][0] + (s[i] == 'r' ? 0 : 1);
            // 从只有 r 和 ry 这两种排列中扩展，取需要交换次数最少的
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (s[i] == 'y' ? 0 : 1);
            // 从 ry 和 ryr 这两种排列中扩展，取需要交换次数最少的
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (s[i] == 'r' ? 0 : 1);
        }

        return dp[n - 1][2];
    }
};