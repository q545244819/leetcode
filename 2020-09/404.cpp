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
        int ans;
        int sumOfLeftLeaves(TreeNode* root) {
            dfs(root);
            return ans;
        }

        TreeNode* dfs (TreeNode* root) {
            if (root == NULL) 
                return NULL;

            TreeNode* left = dfs(root->left);
            
            if (left != NULL && left->left == NULL && left->right == NULL)
                ans += root->left->val;

            TreeNode* right = dfs(root->right);
            
            return root;
        }
    };