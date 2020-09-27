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
    vector<TreeNode*> path;
    vector<TreeNode*> s1;
    vector<TreeNode*> s2;
    TreeNode* ans = NULL;
    int found = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    void dfs (TreeNode* r, TreeNode* p, TreeNode* q) {
        if (r == NULL || found == 2)
            return;
    
        if (r == p) {
            s1 = path;
            s1.push_back(r);
            found++;
        }
        if (r == q) {
            s2 = path;
            s2.push_back(r);
            found++;
        }
        if (found == 2) {
            int p1 = 0, p2 = 0;
            while (p1 < s1.size() && p2 < s2.size()) {
                if (s1[p1] == s2[p2]) {
                    p1++;
                    p2++;
                } else {
                    break;
                }
            }
            if (p1 < s1.size() && p2 < s2.size()) {
                ans = s1[p1 - 1];
            } else if (p1 < s1.size()) {
                ans = s1[p1 - 1];
            } else if (p2 > s2.size()) {
                ans = s2[p2 - 1];
            } else {
                ans = s1.back();
            }
            return;
        }
        
        path.push_back(r);
        dfs(r->left, p, q);
        dfs(r->right, p, q);
        path.pop_back();
    }
};