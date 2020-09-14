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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        
        while (root != NULL || !s.empty()) {
            while (root != NULL) {
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();
            ans.push_back(root->val);
            root = root->right;
        }

        return ans;
    }
};