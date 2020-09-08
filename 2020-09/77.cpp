class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<vector<int>> combine(int n, int k) {
        if (n == 0 || k == 0) return {{}};
        dfs(0, 0, res, n, k);
        return ans;
    }
    void dfs (int i, int step, vector<int>& res, int n, int k) {
        if (step >= k) {
            ans.push_back(res);
            return;
        }

        // 剪枝优化
        // 当剩余可选的数量小于待选的数量，意思就是即便把后面所有可选的数都选了，也还是达不到 k 个数的情况
        // 当剩余可选的数量： n - i + 1
        // 待选的数量：k - res.size()
        if (n - i + 1 < k - res.size()) return;

        for (int j = i + 1; j <= n; j++) {
            res.push_back(j);
            dfs(j, step + 1, res, n, k);
            res.pop_back();
        }
    }
};