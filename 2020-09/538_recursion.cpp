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
    int num = 0;
    TreeNode* convertBST(TreeNode* root) {
        // 思路：利用中序序列，若左根右顺序的话，返回的序列是升序的，那么右根左的话，返回的序列是降序的
        if (root == NULL)
            return root;
        
        convertBST(root->right);
        root->val += num;
        // num 用来记录序列中上一个最大的值
        num = root->val;
        convertBST(root->left);        

        return root;
    }
};