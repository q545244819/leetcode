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
        int m = (l + r) / 2;
        
        TreeNode* root = new TreeNode(nums[m]);
        
        if (l == r) return root;

        if (m - 1 >= l)
            root->left = dfs(nums, l, m - 1);
        if (m + 1 <= r)
            root->right = dfs(nums, m + 1, r);

        return root;
    }
};