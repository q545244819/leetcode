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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // bfs 且使用 hashtable 保存结点的父节点用于找到完整的路径
        if (root == NULL)
            return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;
        vector<TreeNode*> res;
        unordered_map<TreeNode*, TreeNode*> parent;

        q.push({ root, sum - root->val });

        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front(); q.pop();
            TreeNode* cur = front.first;
            if (cur->left == NULL && cur->right == NULL && front.second == 0) {
                res.push_back(cur);
                continue;
            }

            if (cur->left != NULL) {
                parent[cur->left] = cur;
                q.push({ cur->left, front.second - cur->left->val });
            }
            if (cur->right != NULL) {
                parent[cur->right] = cur;
                q.push({ cur->right, front.second - cur->right->val });
            }
        }

        list<int> l;

        for (auto node : res) {
            l.clear();
            while (parent.find(node) != parent.end()) {
                l.push_front(node->val);
                node = parent[node];
            }
            l.push_front(node->val);
            vector<int> arr;
            for (auto el : l)
                arr.push_back(el);
            ans.push_back(arr);
        }

        return ans;
    }
};