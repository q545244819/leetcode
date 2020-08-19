class Solution {
public:
    int countSubstrings(string s) {
        // 动态规划计数
        int ans = 0;
        int n = s.length();

        // dp[i][j] 表示从 s[i] 到 s[j] 是否构成回文串
        // 已知一个字符串 s 为回文串，若在该字符串左右两边都添加一个相同的字符串构成一个新的回文串，s 称为该串的回文中心串
        vector<vector<bool>> dp(n, vector<bool>(n));
    
        // 从二维数组的右下角开始遍历
        // 假如 n = 3 时，遍历的顺序
        // 4 5 6
        // 0 2 3
        // 0 0 1
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                    ans++;
                }
                else if (j - i == 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    ans++;
                }
                else if (j - i > 1 && s[i] == s[j] && dp[i + 1][j - 1]) { // 若dp[i + 1][j - 1] 为 true 且 s[i] == s[j] 则是 dp[i][j] 的回文中心
                    dp[i][j] = true;
                    ans++;
                }
            }

        return ans;
    }
};