class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length() + 1, 0);
        int ans = 0;

        for (int i = 1; i < s.length(); i++) {
            // 第一种情况 ...()
            // dp[i] = dp[i - 2] + 2; 要注意 i - 2 是否越界
            // 第二种情况 ...))
            // dp[i] = d[i - 1] + 2 + dp[i - dp[i - 1] - 2] 要注意 i - dp[i - 1] - 1 和 i - dp[i - 1] - 2 是否越界
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] += i - 2 >= 0 ? dp[i - 2] + 2 : 2;
            } else if (s[i] == ')' && s[i - 1] == ')') {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] += dp[i - 1] + 2;

                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] += dp[i - dp[i - 1] - 2];
                }
            }

            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};