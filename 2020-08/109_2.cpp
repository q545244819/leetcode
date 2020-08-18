/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> list;
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        while (head != NULL)
            list.push_back(head->val), head = head->next;
        return dfs(0, list.size() -1);
    }
    TreeNode* dfs (int l, int r) {
        int m = l + ((r - l) >> 1);

        if (l == r) return new TreeNode(list[m]);
        if (l > r) return NULL;
        
        TreeNode* root = new TreeNode(list[m], dfs(l, m - 1), dfs(m + 1, r));

        return root;
    }
};