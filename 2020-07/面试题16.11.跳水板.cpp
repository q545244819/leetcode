class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> ans;
        if (k == 0) return ans;
        unordered_map<int, bool> M;
        for (int i = k; i >= 0; i--) {
            int res = longer * (k - i) + shorter * i;
            if (!M[res]) {
                ans.push_back(res);
                M[res] = true;
            }
        }
        return ans;
    }
};