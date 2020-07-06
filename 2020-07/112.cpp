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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);   
    }

    bool dfs (TreeNode* root, int num) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && num - root->val == 0)
            return true;

        return dfs(root->left, num - root->val) || dfs(root->right, num - root->val);
    }
};