class Solution {
public:
    int nthUglyNumber(int n) {
        // 重要的事情说三遍
        // 算法核心：忽略不是“丑数”的数字，只考虑丑数的情况
        // 算法核心：忽略不是“丑数”的数字，只考虑丑数的情况
        // 算法核心：忽略不是“丑数”的数字，只考虑丑数的情况
        // 一个丑数一定是另一个丑数 *2、*3 或 *5 得到的。
        // 只需要考虑在一个有序的丑数序列中，下一个丑数是哪一个丑数这个问题
        if (n < 0) return 0;

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        int two = 0, three = 0, five = 0;

        for (int i = 1; i < n; i++) {
            // 下一个最大的丑数，是从前面丑数中 * 2 大于当前序列中的最大丑数、前面丑数中 * 3 大于当前序列中的最大丑数和前面丑数中 * 5 大于当前序列中的最大丑数三者中的最小值
            int mmin = min(dp[two] * 2, min(dp[three] * 3, dp[five] * 5));
            // dp[i] 表示目前情况下，序列中最大的丑数
            dp[i] = mmin;

            // dp[two] 表示在 two 这个位置的丑数 *2 会得到一个比当前序列最大丑数要大的第一个丑数
            // dp[three] 和 dp[five] 的作用与上面的描述相同
            while (dp[two] * 2 <= dp[i])
                two++;
            while (dp[three] * 3 <= dp[i])
                three++;
            while (dp[five] * 5 <= dp[i])
                five++;
        }
        
        return dp[n - 1];
    }
};