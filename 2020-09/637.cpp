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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL)
            return {};
        
        vector<double> ans;
        int last = 0;
        double cnt = 0;
        double sum = 0;
        queue<pair<TreeNode*, int>> q;
        
        q.push({ root, 1 });

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front(); q.pop();
            TreeNode* node = front.first;
            int level = front.second;
            
            if (level != last && last != 0) {
                ans.push_back(sum / cnt);
                sum = 0;
                cnt = 0;
            }

            sum += node->val;
            cnt++;
            last = level;
            
            if (node->left != NULL)
                q.push({ node->left, level + 1 });
            if (node->right != NULL)
                q.push({ node->right, level + 1 });
        }
        
        ans.push_back(sum / cnt);

        return ans;
    }
};