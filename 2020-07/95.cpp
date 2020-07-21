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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }

    vector<TreeNode*> dfs (int l, int r) {
        if (l > r) return { NULL };
        if (l == r) {
            TreeNode* node = new TreeNode(l);
            return { node };
        }

        vector<TreeNode*> res;

        for (int i = l; i <= r; i++) {
            vector<TreeNode*> lefts = dfs(l, i - 1);
            vector<TreeNode*> rights = dfs(i + 1, r);

            for (TreeNode* left: lefts) {
                for (TreeNode* right: rights) {
                    TreeNode* node = new TreeNode(i, left, right);
                    res.push_back(node);
                }
            }
        }

        return res;
    }
};