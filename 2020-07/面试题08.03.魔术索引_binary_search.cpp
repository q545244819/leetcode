class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    int dfs (vector<int>& nums, int l, int r) {
        if (l > r) return -1;

        int m = l + ((r - l) >> 1);
        int left = dfs(nums, l, m - 1);
        if (left != -1) return left;
        else if (m == nums[m]) return m;
        else return dfs(nums, m + 1, r);
    }
};