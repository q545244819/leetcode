class Solution {
public:
    set<vector<int>> ans;
    vector<int> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates, target);
        vector<vector<int>> result;
        for (set<vector<int>>::iterator it = ans.begin(); it != ans.end(); it++)
            result.push_back(*it);
        return result;
    }
    void dfs (int idx, int sum, vector<int>& candidates, int target) {
        if (sum == 0) {
            ans.insert(res);
            return;
        }
        if (sum < 0 || idx >= candidates.size()) {
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if (target < candidates[i])
                continue;
            if (i > idx && candidates[i - 1] == candidates[i])
                continue;
            
            res.push_back(candidates[i]);
            dfs(i + 1, sum - candidates[i], candidates, target);
            res.pop_back();
        }
    }
};