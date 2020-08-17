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
    int ans = 0;
    int cnt = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    // 中序遍历
    // 由于求的是第 k 大的数，所以中序遍历的顺序是：右-根-左
    void dfs (TreeNode* root, int k) {
        if (root == NULL) return;
        
        dfs(root->right, k);
        cnt++;
        if (cnt == k)
            ans = root->val;
        dfs(root->left, k);
    }
};