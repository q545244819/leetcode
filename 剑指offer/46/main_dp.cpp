class Solution {
public:
    int translateNum(int num) {
        string number = to_string(num);
        int len = number.length();
        vector<int> dp(len + 1, 0);
        int cnt = 0;

        // 从后往前分析
        for (int i = len - 1; i >= 0; i--) {
            cnt = 0;
            if (i < len - 1)
                cnt = dp[i + 1];
            else // 当 i == len - 1 时，只有一个字母
                cnt = 1;
            
            if (i < len - 1) {
                int n = (number[i] - '0') * 10 + (number[i + 1] - '0');
                // 当 num[i] 与 num[i + 1] 拼接而成当十位数在 10 到 25 范围内，算是一个字母
                if (n >= 10 && n <= 25) {
                    if (i < len - 2)
                        cnt += dp[i + 2];
                    else
                        cnt++;
                }
            }

            dp[i] = cnt;
        }

        return dp[0];
    }
};