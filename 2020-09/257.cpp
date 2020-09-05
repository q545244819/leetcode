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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};
        dfs(root, "");
        return ans;
    }

    void dfs (TreeNode* root, string res) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(res + to_string(root->val));
            return;
        }

        if (root->left != NULL)
            dfs(root->left, res + to_string(root->val) + "->");
        if (root->right != NULL)
            dfs(root->right, res + to_string(root->val) + "->");
    }
};