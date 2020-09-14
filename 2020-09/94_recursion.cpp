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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs (TreeNode* root) {
        if (root == NULL)
            return;
        
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};