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
    vector<TreeNode*> seq;
    TreeNode* convertBST(TreeNode* root) {
        // 思路：先获取二查搜索树的中序序列，然后再从后往前累加
        dfs(root);
        int n = seq.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 >= n)
                continue;
            seq[i]->val += seq[i + 1]->val;
        }
        return root;
    }
    void dfs (TreeNode* root) {
        if (root == NULL)
            return;

        dfs(root->left);
        seq.push_back(root);
        dfs(root->right);
    }
};