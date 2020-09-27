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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 思路：利用二查搜索树的特性
        // 1.若 p 和 q 结点同是不为 root 结点的左子结点或者右子结点，则直接返回 root 结点
        // 2.若 p 和 q 结点同时小于 root 结点，则表示公共结点是 root 结点的左子结点
        // 3.若 p 和 q 结点同时小于 root 结点，则表示公共结点是 root 结点的右子结点
        if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val)) // 1
            return root;

        if (root->val > p->val && root->val > q->val) // 2
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) // 3
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};