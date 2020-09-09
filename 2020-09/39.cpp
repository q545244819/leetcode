class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 思路：回溯算法
        int n = candidates.size();
        dfs(0, 0, target, candidates);
        return ans;
    }
    void dfs (int i, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            ans.push_back(res);
            return;
        }
        if (sum > target || i >= candidates.size())
            return;
        
        // 跳过当前选择
        dfs(i + 1, sum, target, candidates);
        
        // 选择当前数值，或是继续选择上一个数值
        if (target - candidates[i] >= 0) {
            res.push_back(candidates[i]);
            dfs(i, sum + candidates[i], target, candidates);
            res.pop_back();
        }
    }
};