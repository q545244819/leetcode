/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs (vector<int>& nums, int l, int r) {
        // 为什么 int mid = (l + r)/2会有溢出风险？而int mid = l + (r-l)/2没有呢？？
        // int 最大值是 INT_MAX，大概 20 多亿吧。如果 l 为 20亿，r 也是 20亿+1，相加会变负数。如果使用 l+(r-l)/2 就没有这样的风险。
        int m = l + (r - l) / 2;
        
        TreeNode* root = new TreeNode(nums[m]);

        if (m - 1 >= l)
            root->left = dfs(nums, l, m - 1);
        if (m + 1 <= r)
            root->right = dfs(nums, m + 1, r);

        return root;
    }
};