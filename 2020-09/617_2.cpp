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
    int mmax = 0;
    int i = 0;
    int begin = 0;
    int prev = INT_MIN;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        // 思路：利用二叉搜索树中序序列已排序的特性，相同的数字总是相邻的。
        // 时间复杂度O(n)，空间复杂度O(1)常数
        if (root == NULL)
            return {};
        dfs(root);
        return ans;
    }

    void dfs (TreeNode* root) {
        if (root == NULL)
            return;
        
        dfs(root->left);
        // 中序序列开始
        if (root->val != prev) { // 若当前结点的值与上一个结点值不相同，设置 begin 为当前节点在中序序列中的位置
            begin = i;
        }
        // 上一个结点值和当前结点值相同，表示出现一个众数
        // 计算该众数出现的次数，只要连续出现都会进入判断
        if (i - begin + 1 >= mmax) {
            if (i - begin + 1 > mmax) // 若出现的次数比最大次数要多，清空结果数组
                ans.clear();
            mmax = i - begin + 1; // 计算当前众数出现的最大次数
            ans.push_back(root->val);
        }
        prev = root->val; // 更新上一个结点值
        i++; // 中序序列的下标偏移

        dfs(root->right);
    }
};