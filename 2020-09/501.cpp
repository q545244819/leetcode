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
    vector<int> seq;
    vector<int> findMode(TreeNode* root) {
        if (root == NULL)
            return {};
        
        dfs(root);

        int mmax = 1;
        int i = 1, begin = 0;
        vector<int> ans;

        for (i = 1; i < seq.size(); i++) {
            if (seq[i] != seq[i - 1] && i - begin >= mmax) {
                if (i - begin > mmax)
                    ans.clear();
                mmax = i - begin;
                begin = i;
                ans.push_back(seq[i - 1]);
            } else if (seq[i] != seq[i - 1]) {
                begin = i;
            }
        }
        
        if (i > begin && i - begin >= mmax) {
            if (i - begin > mmax)
                ans.clear();
            mmax = i - begin;
            begin = i;
            ans.push_back(seq[i - 1]);
        }
        return ans;
    }

    void dfs (TreeNode* root) {
        if (root == NULL)
            return;
        
        dfs(root->left);
        seq.push_back(root->val);
        dfs(root->right);
    }
};