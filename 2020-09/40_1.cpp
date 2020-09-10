class Solution {
public:
    set<vector<int>> ans;
    vector<int> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        vector<vector<int>> result;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end(); it++)
            result.push_back(*it);
        return result;
    }
    void dfs (int idx, int sum, vector<int>& candidates) {
        if (sum == 0) {
            ans.insert(res);
            return;
        }
        if (sum < 0 || idx >= candidates.size()) {
            return;
        }

        // 选
        res.push_back(candidates[idx]);
        dfs(idx + 1, sum - candidates[idx], candidates);
        res.pop_back();

        // 不选
        dfs(idx + 1, sum, candidates);
    }
};