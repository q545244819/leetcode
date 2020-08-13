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
    vector<TreeNode*> record;
    void flatten(TreeNode* root) {
        dfs(root);
        TreeNode* head = root;
        for (int i = 1; i < record.size(); i++) {
            head->left = NULL;
            head->right = new TreeNode(record[i]->val);
            head = head->right;
        }
    }
    void dfs (TreeNode* root) {
        if (root == NULL) return;

        record.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
};