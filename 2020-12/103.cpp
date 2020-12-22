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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        
        vector<vector<int>> ans;

        queue<pair<TreeNode*, int>> Q;
        int cur = -1;

        Q.push({ root, 0 });

        while (!Q.empty()) {
            auto front = Q.front(); Q.pop();

            if (cur != front.second)
                ans.push_back({});
            
            cur = front.second;
            
            ans[cur].push_back(front.first->val);

            if (front.first->left != NULL)
                Q.push({ front.first->left, front.second + 1 });
            if (front.first->right != NULL)
                Q.push({ front.first->right, front.second + 1 });
        }

        for (int i = 0; i < ans.size(); i++)
            if (i & 1)
                reverse(ans[i].begin(), ans[i].end());

        return ans;
    }
};