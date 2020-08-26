class Solution {
public:
    int n = 0;
    set<vector<int>> S;
    vector<vector<int>> ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        
        for (int i = 0; i < n; i++)
            dfs(i, {nums[i]}, nums);

        return ans;
    }

    void dfs (int idx, vector<int> res, vector<int>& nums) {
        //cout << idx << " " << res.size() << endl;
        if (S.find(res) != S.end()) {
            return;
        }
        if (res.size() >= 2) {
            // cout << "res: ";
            // for (int num : res)
            //     cout << num << ' ';
            // cout << endl;
            ans.push_back(res);
            S.insert(res);
        }
        if (idx >= n) {
            return;
        }

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] >= res.back()) {
                // 接上一个数
                res.push_back(nums[i]);
                dfs(i, res, nums);
                res.pop_back();
            }
            // 重新开始
            //dfs(i, { nums[i] }, nums);
        }
    }
};