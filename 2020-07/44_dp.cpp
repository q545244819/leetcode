class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));

        // 空字符串
        dp[0][0] = 1;
        // 匹配串中开头的 * 可以匹配的字符
        for (int i = 0; p[i] == '*'; i++) dp[0][i + 1] = dp[0][i];

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                // 当前字符相同或者为 ? 匹配随机一个字符，从上一个状态转移
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                // 当前字符为 *，从两个状态转移
                // 第一个，上一个字符也使用 * 匹配
                // 第二个，上一个字符不使用 * 匹配
                else if (p[j - 1] == '*')
                    if (dp[i - 1][j] || dp[i][j - 1])
                        dp[i][j] = true;
            }
        }

        return dp[s.length()][p.length()];
    }
};