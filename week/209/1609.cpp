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
    bool isEvenOddTree(TreeNode* root) {
        if (root == NULL)
            return false;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, 1 });
        int last = 0;
        int lastVal = root->val;
        unordered_map<int, int> counts;
        if ((root->val & 1) == 0)
            return false;
        while (!q.empty()) {
            pair<TreeNode*, int> front = q.front(); q.pop();
            
            if (last == front.second) {
                //cout << "1 " << last << ' ' << lastVal << ' ' << front.first->val << endl;
                if ((last & 1) == 0) {
                    if ((lastVal & 1) || (front.first->val & 1))
                        return false;
                    if (lastVal <= front.first->val)
                        return false;
                } else {
                    if ((lastVal & 1) == 0 || (front.first->val & 1) == 0)
                        return false;
                    if (lastVal >= front.first->val)
                        return false;
                }
            } else {
                //cout << "2 " << last << ' ' << lastVal << ' ' << front.first->val << endl;
                if (counts[front.second] == 1) {
                    if ((front.second & 1) == 0 && (front.first->val & 1))
                        return false;
                    else if ((front.second & 1) && (front.first->val & 1) == 0)
                        return false;
                }
            }
            last = front.second;
            lastVal = front.first->val;
            
            if (front.first->left != NULL) {
                q.push({ front.first->left, front.second + 1 });
                counts[front.second + 1]++;
            }
            if (front.first->right != NULL) {
                q.push({ front.first->right, front.second + 1 });
                counts[front.second + 1]++;
            }
        }
        return true;
    }
};