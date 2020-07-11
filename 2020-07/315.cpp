/*
    🙏感谢来自评论区的@江不知题解
    利用二叉搜索树的特性：左边节点的值小于等于当前节点值，右边节点的值大于等于当前节点值。

    那么实现算法首先要构建一颗二叉搜索树：

    定义树的节点结构 TreeNode
    实现树的节点插入方法 insertNode
    其中， insertNode 方法需要实现几个功能：

    构建二叉树
    维护每个节点中其左子树节点数量值 count：如果新加入的节点需要加入当前节点的左子树，则当前节点的 count += 1
    计算出新加入节点 nums[i] 的 "右侧小于当前元素的个数"，即题目所求值 res[i]
*/
class BTSNode {
    public:
        BTSNode* left;
        BTSNode* right;
        int val;
        int leftCnt = 0;
        BTSNode (int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class Solution {
public:
    vector<int> ans;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return ans;
        BTSNode* root = new BTSNode(nums[n - 1]);

        ans.resize(n);
        ans[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
            insert(root, nums[i], i);

        return ans;
    }

    BTSNode* insert (BTSNode* root, int val, int index) {
        if (root == NULL) {
            return new BTSNode(val);
        }

        if (root->val >= val) {
            root->leftCnt++;
            root->left = insert(root->left, val, index);
        } else {
            ans[index] += root->leftCnt + 1;
            root->right = insert(root->right, val, index);
        }

        return root;
    }
};