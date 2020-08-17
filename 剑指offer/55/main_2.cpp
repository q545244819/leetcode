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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }

    // 求深度的同时，判断左右字数的深度差是否超过 1
    int dfs (TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (abs(left - right) > 1)
            res = false;
        
        return 1 + max(left, right);
    }
};