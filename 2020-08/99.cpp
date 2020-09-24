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
    vector<TreeNode*> seq;
    void recoverTree(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root);
        // for (auto num : seq)
        //     cout << num->val << ' ';
        // cout << endl;
        for (int i = 0; i < seq.size(); i++) {
            int idx = i;
            for (int j = i + 1; j < seq.size(); j++) {
                if (seq[i]->val > seq[j]->val)
                    idx = j;
            }
            if (idx != i) {
                //cout << i << ' ' << idx << endl;
                swap(seq[i]->val, seq[idx]->val);
                break;
            }
        }
    }
    void dfs (TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        seq.push_back(root);
        dfs(root->right);
    }
};