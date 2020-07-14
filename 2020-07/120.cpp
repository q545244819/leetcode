class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 时间复杂度O(n^2)，空间复杂度O(n)
        int n = triangle.size();
        if (n == 0) return 0;
        if (n == 1) return triangle[0][0];
        
        const int mmax = 2 << 21;
        int ans = mmax;
        vector<int> dp(n + 1, mmax);
        vector<int> temp;
        
        dp[0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            temp = dp;

            for (int j = 0; j < triangle[i].size(); j++) {
                if (j - 1 >= 0)
                    dp[j] = min(temp[j] + triangle[i][j], temp[j - 1] + triangle[i][j]);
                else
                    dp[j] = temp[j] + triangle[i][j];
                
                if (i == n -1)
                    ans = min(ans, dp[j]);
            }
        }

        return ans;
    }
};