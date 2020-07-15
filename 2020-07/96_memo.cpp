class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.resize(n + 1);
        fill(dp.begin(), dp.end(), 0);
        return dfs(n);
    }
    int dfs (int n) {
        if (n == 0 || n == 1) return dp[n] = 1;
        if (dp[n]) return dp[n];
        int res = 0;
        for (int i = 0; i < n; i++)
            res += dfs(i) * dfs(n - 1 - i);
        return dp[n] = res;
    }
};