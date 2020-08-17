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
    unordered_map<TreeNode*, int> memo;
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return (abs(dfs(root->left) - dfs(root->right)) <= 1) && left && right;
    }

    int dfs (TreeNode* root) {
        if (root == NULL) return 0;
        if (memo.find(root) != memo.end()) return memo[root];
        
        return memo[root] = 1 + max(dfs(root->left), dfs(root->right));
    }
};