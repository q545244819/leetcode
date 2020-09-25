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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 思路：和中序+前序构建二叉树的做法一样，注意后序的话，根结点在最后
        int n = postorder.size();
        if (n == 0)
            return NULL;
        return dfs(n - 1, 0, n - 1, inorder, postorder);
    }

    TreeNode* dfs (int idx, int l, int r, vector<int>& inorder, vector<int>& postorder) {
        // 处理边界情况，若 l > r 则表示无左子树或右子树
        if (l > r)
            return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        // 处理边界情况，若 l == r 则表示没有当前结点没有子结点      
        if (l == r)
            return root;

        // 计算当前结点左子节点的数量
        int i = l;
        while (inorder[i] != postorder[idx]) {
            i++;
        }

        // 构建左子树
        // 根据左子结点的数量，计算出右子树结点的数量 (r - i) + 1
        root->left = dfs(idx - (r - i) - 1, l, i - 1, inorder, postorder);

        // 构建右子树
        // 找到左子结点在中序的位置后，下一个位置就是右子结点的开始（可能溢出）
        root->right = dfs(idx - 1, i + 1, r, inorder, postorder);

        return root;
    }
};