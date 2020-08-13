/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Node {
    public:
        int does;
        int dont;
        Node* left;
        Node* right;
        Node(int does, int dont) {
            this->does = does;
            this->dont = dont;
            this->left = NULL;
            this->right = NULL;
        }
};

class Solution {
public:
    int rob(TreeNode* root) {
        Node* res = dfs(root);

        return max(res->does, res->dont);
    }

    Node* dfs (TreeNode* root) {
        Node* node = new Node(0, 0);

        if (root == NULL) return node;

        node->left = dfs(root->left);
        node->right = dfs(root->right);

        // 若当前房子抢
        // 则最优结果 = 当前房子的价值加上左边房子不抢的最优结果和右边房子不抢的最优结果
        node->does = root->val + node->left->dont + node->right->dont;
        // 若当前房子不抢
        // 则可以选择下面的左边的房子抢或不抢和右边房子抢或不抢
        // 则最优结果 = max(左边的房子抢, 左边的房不抢) + max(右边的房子抢, 右边的房不抢)
        node->dont = max(node->left->does, node->left->dont) + max(node->right->does, node->right->dont);

        printf("%d %d %d\n", root->val, node->does, node->dont);

        return node;
    }
};