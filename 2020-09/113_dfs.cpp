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
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;
        path.push_back(root->val);
        dfs(root, sum - root->val, sum);
        return ans;
    }
    
    void dfs (TreeNode* root, int sum, int target) {
        if (sum == 0 && root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        if (root->left != NULL) {
            path.push_back(root->left->val);
            dfs(root->left, sum - root->left->val, target);
            path.pop_back();
        }

        if (root->right != NULL) {
            path.push_back(root->right->val);
            dfs(root->right, sum - root->right->val, target);
            path.pop_back();
        }
    }
};