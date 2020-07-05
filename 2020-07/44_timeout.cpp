class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        return (bool)match(s, p, dp, 0, 0);
    }

    int match (string s, string p, vector<vector<int>>& dp, int i, int j) {
        if (i >= s.length() && j >= p.length()) return dp[i][j] = 1;
        if (j >= p.length()) return dp[i][j] = 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == '*') {
            // * 的三种模式
            // 第一种，匹配多次
            // 第二种，匹配一次
            // 第三种，匹配零次
            if (i < s.length()) {
                return dp[i][j] = match(s, p, dp, i + 1, j) || match(s, p, dp, i + 1, j + 1) || match(s, p, dp, i, j + 1);
            } else {
                return dp[i][j] = match(s, p, dp, i, j + 1);
            }
        }

        if (s[i] == p[j] || (i < s.length() && p[j] == '?')) {
            return dp[i][j] = match(s, p, dp, i + 1, j + 1);
        }

        return dp[i][j] = 0;
    }
};