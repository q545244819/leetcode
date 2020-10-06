class Solution {
public:
    vector<int> s;
    vector<int> dp;
    vector<vector<int>> g;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        // 思路：换根树状 DP
        // 通常需要两个 dfs，第一个用于处理树的深度、权重等信息，第二个 dfs 开始运行换根动态规划
        s = vector<int>(N, 0);
        dp = vector<int>(N, 0);
        g = vector<vector<int>>(N);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, 0);
        dfs2(0, 0, N);

        return dp;
    }
    // 预处理
    void dfs (int u, int f) {
        for (int v : g[u]) {
            if (v == f)
                continue;
            dfs(v, u);
            s[u] += s[v];
            dp[u] += dp[v];
        }
        s[u]++;
        dp[u] += s[u] - 1;
    }
    // 运行动态规划
    void dfs2 (int u, int f, int N) {
        for (int v : g[u]) {
            if (v == f)
                continue;
            dp[v] = dp[u] - s[v] * 2 + N;
            dfs2(v, u, N);
        }
    }
};