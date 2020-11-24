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
    int countNodes(TreeNode* root) {
        // 思路：递归
        // 1.首先根据完全二叉树的定义，一直搜索根结点的最左叶结点，得到树高，再一直搜索根结点的最右叶结点，再次得到树高，若两个树高相同，则证明是一个满的完全二叉树，结点数量为 2^树高 - 1
        // 2.若左右的树高不同，则递归左子树和右子树，当前根结点的结点数量等于左子树的结点数量和右子树的结点数量加一
        int left = 0, right = 0;
        TreeNode* cur = root;

        while (cur) {
            cur = cur->left;
            left++;
        }

        cur = root;

        while (cur) {
            cur = cur->right;
            right++;
        }

        if (left == right)
            return pow(2, left) - 1;
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};