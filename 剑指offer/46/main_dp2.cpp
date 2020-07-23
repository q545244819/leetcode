class Solution {
public:
    int translateNum(int num) {
        string number = to_string(num);
        int len = number.length();
        vector<int> dp(len + 1, 0);
        int cnt = 0;

        dp[len] = dp[len - 1] = 1;

        // 从后往前分析
        for (int i = len - 2; i >= 0; i--) {
            int n = (number[i] - '0') * 10 + (number[i + 1] - '0');
            if (n >= 10 && n <= 25)
                dp[i] = dp[i + 1] + dp[i + 2];
            else
                dp[i] = dp[i + 1];
        }

        return dp[0];
    }
};