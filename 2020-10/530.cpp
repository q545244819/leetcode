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
    int prev = INT_MAX;
    int ans = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        // 思路：中序周游
        dfs(root);
        return ans;
    }
    void dfs (TreeNode* r) {
        if (r == NULL)
            return;
        
        dfs(r->left);
        if (prev == INT_MAX)
            prev = r->val;
        else {
            ans = min(ans, r->val - prev);
            prev = r->val;
        }
        dfs(r->right);
    }
};