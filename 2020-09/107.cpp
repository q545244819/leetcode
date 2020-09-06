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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) return {};

        list<pair<TreeNode*, int>> res;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        
        q.push({ root, 1 });

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front(); q.pop();

            res.push_front(front);

            if (front.first->left != NULL)
                q.push({ front.first->left, front.second + 1 });
            if (front.first->right != NULL)
                q.push({ front.first->right, front.second + 1 });
        }

        int deep = res.front().second + 1;
        
        for (pair<TreeNode*, int> el : res) {
            if (el.second < deep) {
                if (ans.size() > 0)
                    reverse(ans.back().begin(), ans.back().end());
                ans.push_back({});
            }
            ans.back().push_back(el.first->val);
            deep = el.second;
        }

        return ans;
    }
};