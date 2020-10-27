/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 思路：用栈模拟前序遍历递归
        if (root == NULL)
            return {};

        vector<int> ans;
        stack<TreeNode*> S;

        while (!S.empty() || root != NULL) {
            while (root != NULL) {
                ans.push_back(root->val);
                S.push(root);
                root = root->left;
            }
            
            root = S.top();
            S.pop();
            root = root->right;
        }

        return ans;
    }
};